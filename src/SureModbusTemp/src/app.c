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

void app_main (void)
{
  ADCSRA |= (1<< ADSC);
  _delay_ms(1);
  printf("ADCH= %u  ", ADCH);
  
  int32_t k = 1040;
  int32_t d = -96000;
  int16_t mbInputReg01;
  
  int32_t x = k*ADCH + d;
  if(x> 0x7fff) {
    mbInputReg01 = 0x7fff;
  } else if(x < -32768) {
    mbInputReg01 = -0x8000;
  } else {
    mbInputReg01 = (int8_t)x;
  }
  printf("Versuch: %d \r",mbInputReg01);
  
  
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



