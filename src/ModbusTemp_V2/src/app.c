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

void app_handleUartByte(char c) {
  
  if(c == ':') {
    app.bufferIndex=0;
    app.modbusBuffer[app.bufferIndex] = c;
    app.bufferIndex=1;
  } else{
    if(app.bufferIndex > 0) {
      app.modbusBuffer[app.bufferIndex++] = c;
    }
  }
  
  
  
  
  
}

void app_main (void)
{
  ADCSRA |= (1<< ADSC);
  _delay_ms(1);
  uint8_t adch = ADCH;
  //adch = 88;
  //printf("ADCH= %u  ", adch);
  //Gerade ModbusRegister = k * ADCH + d
  // aus Datenblatt: 
  //  -45°C -> 242mV -> ADCH=56.79 -> MBR = 45*256 = -11520
  //  25°C -> 314mV -> ADCH=73.08 -> MBR = 25*256 = 6400
  //  85°C -> 380mV -> ADCH=88.40 -> MBR = 85*256 + 21760
  //daraus ergibt sch für:
  //   <=25° -> MBR = k1*ADCH+d1
  //   >25°C -> MBR = k2*ADCH +d2
  float k1 = 1100.061, d1 = -73992.464;
  float k2 = 1002.611, d2 = -66870.812;
  
  //reale Messung bei 22°C -> ADCH=88
  // interpoliert
  //  22°C -> ?? -> ADCH=72.38 -> MBR = 22*256 + (56320)
  //Offsetkorrektur um bei ADCH=88 auf 5632 zu kommen
  //  ADCH <=88 -> MBR = k1*ADCH+d1+o1
  // ADCH >88 -> MBR = k2*ADCH+d2+o2
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
  
  
  //printf("MBR = %d = 0x%04x", mbInputReg01, (uint16_t)mbr);
  //printf(" T:%d.%02d ", vk, (int)nk);
  
  
/*
  int32_t k = 1040;
  int32_t d = -96000;
  
  int32_t x = k * adch + d;
  if(x> 0x7fff) {
    mbInputReg01 = 0x7fff;
  } else if(x < -32768) {
    mbInputReg01 = -0x8000;
  } else {
    mbInputReg01 = (int8_t)x;
  }
  printf("Versuch: %d \r",mbInputReg01);
*/
  //_delay_ms(500);
  
  int c = fgetc(stdin);
  if(c != EOF) {
    printf("\r\n %02x\r\n", (uint8_t)c);
    app_handleUartByte((char) c);
  }
  
  
  
}

//--------------------------------------------------------

void app_task_1ms (void) {}
void app_task_2ms (void) {}
void app_task_4ms (void) {}
void app_task_8ms (void) {}
void app_task_16ms (void) {}
void app_task_32ms (void) {}
void app_task_64ms (void) {}
void app_task_128ms (void) {}



