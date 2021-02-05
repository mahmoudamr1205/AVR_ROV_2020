/*
 * pwm.c
 *
 * Created: 1/31/2021 12:49:43 AM
 *  Author: abdul
 */ 
#define F_CPU 8000000ul
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#define amp 5
  void anlog_write(int pin , float value)
  {
	   
	   float rduty_cycle;
	   float duty_cycle ;
	   switch (pin)
	   {
	   case 1:
		  DDRD|= (1<<DDD6);
		  rduty_cycle =0;
		   duty_cycle =0;
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR0A = (duty_cycle*256) ;
		  TCCR0A |= (1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
		  TCCR0B |= (1<<CS00)|(1<<CS02);
		  break;
	
	      case 2:
		  
		  DDRD|= (1<<DDD5);
		  rduty_cycle =0;
		  duty_cycle =0;
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR0B = (duty_cycle*256) ;
		  TCCR0A |= (1<<WGM00)|(1<<WGM01)|(1<<COM0B1);
		  TCCR0B |= (1<<CS00)|(1<<CS02);
		  break;
	  
	 case 3:
		 
		  DDRB |= (1 << DDB1) ;
		  rduty_cycle =0;
		  duty_cycle =0;  
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR1A = (duty_cycle*256) ;
		   TCCR1A |= (1 << COM1A1);
		   TCCR1A |= (1 << WGM10);
		   TCCR1B |= (1 << WGM12);
		   TCCR1B |= (1 << CS10)|(1 << CS12);
		   break;
	  
	 case  4:
		  DDRB |= (1 << DDB2) ;
		 rduty_cycle =0;
		 duty_cycle =0;
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR1B = (duty_cycle*256) ;
		  TCCR1A |= (1 << COM1B1);
		  TCCR1A |= (1 << WGM10);
		  TCCR1B |= (1 << WGM12);
		  TCCR1B |= (1 << CS10)|(1 << CS12);
		  break;
	  
	  case 5:
		  
		  DDRB |= (1 << DDB3) ;
		 rduty_cycle =0;
		 duty_cycle =0;
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR2A = (duty_cycle*256) ;
		  TCCR2A |= (1 << COM2A1);
		  TCCR2A |= (1 << WGM21) | (1 << WGM20);
		  TCCR1B |= (1 << CS10)|(1 << CS12);
		  TCCR2B |= (1 << CS20)| (1 << CS21)| (1 << CS22);
		  break;
	  

	  case 6:
		 
		  DDRD|= (1<<DDD3);
		  rduty_cycle =0;
		  duty_cycle =0;
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR2B = (duty_cycle*256) ;
		  TCCR2A |= (1 << COM2B1);
		  TCCR2A |= (1 << WGM21) | (1 << WGM20);
		  TCCR1B |= (1 << CS10)|(1 << CS12);
		  TCCR2B |= (1 << CS20)| (1 << CS21)| (1 << CS22);
		  
		   break;
		   default:
		   break;
	  }
	  
	 
  }
