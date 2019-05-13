#include "global.h"

#include <stdio.h>
#include <string.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "app.h"
#include "sys.h"

// defines
// ...


// declarations and definations

volatile struct App app;


// functions

void app_init (void)
{
  memset((void *)&app, 0, sizeof(app));
  ADMUX = 8; //Multiplexer ADC 8 = Temperatursensor
  ADMUX |= (1<<REFS0) | (1<<REFS1); // VREF = 1.1V
  ADMUX |= (1<<ADLAR); //Left Adj, result 
  
  ADCSRA = (1<<ADEN) | 7; // fADC = 125kHz
  ADCSRB = 0;
  
}


//--------------------------------------------------------
uint16_t app_inc16BitCount(uint16_t cnt) {
  //sys_setLed(1);
  return cnt == 0xffff ? cnt : cnt+1;
}

uint8_t hex2int(char h) {
  if(h >= '0' && h<= '9') return h-'0';
  if(h >= 'A' && h<= 'F') return h-'A'+10;
  return 0xff; //Fehler
}

uint8_t app_handleModbusRequest() {
  //printf("Request eingetroffen: %s", app.modbusBuffer);
  
  //Check if valid modbus frame
  char *b = app.modbusBuffer;
  uint8_t size = app.bufferIndex;
  
  if(size < 9) return 1;
  if(b[0] != ':') return 2;
  if(b[size -1] != '\n') return 3;
  if(b[size -2] != '\r') return 4;
  if((size - 3) %2 != 0) return 5;
  for (uint8_t i = 1; i < (size -2); i++) {
    char c= b[i];
    if(!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) return 6;
  }
  
  uint8_t lrc = 0;
  for(uint8_t i = 1;i <(size - 4); i++) {
    lrc += b[i];
  }
  lrc = (uint8_t) (-(int8_t) lrc);
  char s[3];
  snprintf(s, sizeof s, "%02X", lrc);
  if(b[size -4] != s[0] || b[size -4] != s[0]) return 7;
  
  //printf("request geht leida");
  uint8_t i, j;
  for (i = 1, j = 0; i < (size -4); i+=2, j++) {
    uint8_t hn = hex2int(b[i]);
    uint8_t ln = hex2int(b[i+1]);
    if(hn == 0xff || ln == 0xff) {
      return 8;
    }
    uint8_t value = hn *16+ln;
    b[j] = value;
  }
  size = j;
  
  uint8_t deviceAddress = b[0];
  if(deviceAddress != 1) return 0;
  
  uint8_t funcCode = b[1];
  switch(funcCode) {
  case 0x04: {
      uint16_t startAddress = b[2] << 8 | b[3];
      uint16_t quantity = b[4] << 8 | b[5];
      if(quantity < 1 || quantity > 0x7d) {
        b[1] = 0x80 | b[1]; //Error
        b[2] = 0x03; // quantity aou of range
        size = 3;
      } else if(startAddress != 1 || quantity != 1) {
        b[1] = 0x80 | b[1]; //Error
        b[2] = 0x02; //wrong start adress
        size = 3;
      } else {
        b[2] = 2;
        b[3] = app.mbInputReg01 >> 8;
        b[4] = app.mbInputReg01 &0xff;
        size = 5;
      }
      
      break;
  }
  default: {
    b[1] = 0x80 | b[1]; //Error
    b[2] = 0x01; //function code not supported
    size = 3;
  }
  }
  
  lrc= 0;
  printf(":");
  for(i = 0; i<size; i++) {
    printf("%02X", (uint8_t)b[i]);
    lrc += b[i];
  }
  lrc = (uint8_t)(-(int8_t)lrc);
  printf("%02X", lrc);
  printf("\r\n");
  
  return 0;
}


void app_handleUartByte(char c) {
  if(c == ':') {
    
    if(app.bufferIndex > 0) {
      app.errCnt = app_inc16BitCount(app.errCnt);
    }
    
    //app.bufferIndex=0;
    app.modbusBuffer[app.bufferIndex] = c;
    app.bufferIndex=1;
  } else if(app.bufferIndex == 0){
    app.errCnt = app_inc16BitCount(app.errCnt);
    
  } else if (app.bufferIndex >= sizeof(app.modbusBuffer)) {
    app.errCnt = app_inc16BitCount(app.errCnt);
    
  } else {
    
    app.modbusBuffer[app.bufferIndex++] = c;
    if(c == '\n') {
      uint8_t errCode =  app_handleModbusRequest();
      if(errCode != 0) {
        //printf("Fehler: %u\r\n", errCode);
        app.errCnt = app_inc16BitCount(app.errCnt);
      }
      app.bufferIndex = 0;
    }
  }
}

void app_main (void)
{
  ADCSRA |= (1<< ADSC);
  _delay_ms(1);
  uint8_t adch = ADCH;

  float k1 = 1100.061, d1 = -73992.464;
  float k2 = 1002.611, d2 = -66870.812;

  float o1 = -17180.9;
  float o2 = -15776.956;
  
  float mbr;
  if(adch <= 88) {
    mbr = k1 * adch + d1 + o1;
  } else {
    mbr = k2 * adch + d2 + o2;
  }
  int16_t mbInputReg01 = (int16_t)mbr;
  int8_t vk = mbInputReg01/256;
  uint8_t nk = ((mbInputReg01 & 0xff)*100)/256;
  
  app.mbInputReg01= (uint16_t) mbInputReg01;
  
  int c = fgetc(stdin);
  if(c != EOF) {
    //printf("\r\n %02x\r\n", (uint8_t)c);
    app_handleUartByte((char) c);
  }
  
  
  
}

//--------------------------------------------------------

void app_task_1ms (void) {
  static uint16_t oldErrCnt = 0;
  static uint16_t timer = 0;
  if(app.errCnt != oldErrCnt) {
    oldErrCnt = app.errCnt;
    timer = 2000;
    sys_setLed(1);
    printf("Err");
  }
  if(timer > 0) {
    timer--;
    if(timer <= 0) {
      sys_setLed(0);
    }
  }

}
void app_task_2ms (void) {}
void app_task_4ms (void) {}
void app_task_8ms (void) {}
void app_task_16ms (void) {}
void app_task_32ms (void) {}
void app_task_64ms (void) {}
void app_task_128ms (void) {}
