# Protokoll der 7. Einheit

#### app.c

volatile struct App app;


// functions

void app_init (void)
{
  memset((void *)&app, 0, sizeof(app));
  ADMUX = (1<<REFS1) | (1<<REFS0) | (1<<ADLAR) | 0x08; //0x08.... Tempsensor
  ADCSRA = (1<<ADEN) | 7; // durch 128 -> das ergibt eine frequenz von 125kHz (eine ADC Umwandlung benötigt 128µs)
  app.modbus.frameIndex = -1;
}


//--------------------------------------------------------

void app_main (void)
{
/*
  printf("ADCH= %u  \r", app.adch);
  _delay_ms(200);
*/
  printf("-----\n\r");
  printf("  frameIndex: %d\n\r",app.modbusForPrint.frameIndex);
  printf("  frameError: %d\n\r",app.modbusForPrint.frameError);
  printf("ErrorCounter: %d\n\r",app.modbusForPrint.errorcounter);
  printf("  invalidBytes: %d\n\r",app.modbusForPrint.invalidByteCount);
  printf("------\n\r");
  for (int i=0; i <sizeof(app.modbusForPrint.frame);i++)
  {
    printf("%02x",(uint8_t)app.modbusForPrint.frame);
  }
    
    printf("\n\r");
}

//--------------------------------------------------------

void app_task_1ms (void) 
{
  app_handleUartByte();
}
void app_task_2ms (void) {}
void app_task_4ms (void) {}
void app_task_8ms (void) {}
void app_task_16ms (void) {
  app.adch=ADCH;
  ADCSRA |= (1<< ADSC); //Starte ADC
  
}
void app_task_32ms (void) {}
void app_task_64ms (void) {}
void app_task_128ms (void) {}
void app_parseModbusFrame(){
  app.modbusForPrint = app.modbus;
  sys_setEvent(APP_EVENT_MODBUS);
}
void app_handleUartByte (char c)
{
  struct Modbus *p = &app.modbus;
  
  if (p ->frameIndex <0){
    if(c==':'){
      p->frameIndex =0;
      p->frameError =0;
    } else {
      if(p -> invalidByteCount < 0xffff){
        p->invalidByteCount++;
      }
    }
    
  } else {
    if(c==':'){
      p->frameIndex=0;
      p->frameError = 0; 
      if(p->errorcounter < 0xffff)
        p->errorcounter++;
      
    } else {
    
    //in buffer speichern
    if (p->frameIndex < sizeof p->frame)
    p->frame [p->frameIndex++] = c;
    
    else {
      p-> frameError = 1;
    }
    if(c== '\n')
      app_parseModbusFrame();
      p->frameIndex = -1;
      p->frameError = 0; 
    }
  }
}

### app.h

#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

// declarations
struct Modbus
{
  char frame[16];
  uint8_t frameIndex;
  uint16_t errorcounter;
  uint8_t frameError;
  uint16_t invalidByteCount;
};
struct App
{
  uint8_t adch;
  struct Modbus modbus;
  struct Modbus modbusForPrint;
};

extern volatile struct App app;


// defines

#define APP_EVENT_MODBUS   0x01
#define APP_EVENT_1   0x02
#define APP_EVENT_2   0x04
#define APP_EVENT_3   0x08
#define APP_EVENT_4   0x10
#define APP_EVENT_5   0x20
#define APP_EVENT_6   0x40
#define APP_EVENT_7   0x80


// functions

void app_init (void);
void app_main (void);

void app_task_1ms   (void);
void app_task_2ms   (void);
void app_task_4ms   (void);
void app_task_8ms   (void);
void app_task_16ms  (void);
void app_task_32ms  (void);
void app_task_64ms  (void);
void app_task_128ms (void);

void app_handleUartByte(char c);

#endif // APP_H_INCLUDED


### sys.c

int sys_uart_getch (FILE *f)
{
  if (f != stdin)
    return _FDEV_EOF;
  if (sys.uart.wpos_u8 == sys.uart.rpos_u8)
    return _FDEV_EOF;
  uint8_t c = sys.uart.rbuffer_u8[sys.uart.rpos_u8++];
  if (sys.uart.rpos_u8>=GLOBAL_UART_RECBUFSIZE)
    sys.uart.rpos_u8 = 0;
  return (int) c;
}


int sys_uart_putch (char c, FILE *f)
{
  if (f != stdout)
    return _FDEV_EOF;
  while (!SYS_UART_UDR_IS_EMPTY);
  SYS_UDR = c;
  return (int)c;
}

  sys_sei();

Sys_Event sys_clearEvent (Sys_Event event)
{
  uint8_t eventIsPending = 0;
  sys_cli();
  if (sys.eventFlag & event)
    eventIsPending = 1;
  sys.eventFlag &= ~event;
  sys_sei();

  return eventIsPending;
}


Sys_Event sys_isEventPending (Sys_Event event)
{
  return (sys.eventFlag & event) != 0;
}
