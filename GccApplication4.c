/*
 * GccApplication4.c
 *
 * Created: 1/31/2021 12:49:43 AM
 *  Author: abdul
 */ 


#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU 8000000ul

int main(void)
{
	DDRD|= (1<<DDD6)|(1<<DDD5)|(1 << DDD3);
	OCR0A =82;
	OCR0B =82;
	TCCR0A |= (1<<WGM00)|(1<<WGM01)|(1<<COM0A1)|(1<<COM0B1);
	TCCR0B |= (1<<CS00)|(1<<CS02);
	DDRB |= (1 << DDB1)|(1 << DDB2)|(1 << DDB3);
	// PB1 and PB2 is now an output

	//ICR1 = 0xFFFF;
	// set TOP to 16bit

	OCR1A = 64;
	// set PWM for 25% duty cycle @ 16bit

	OCR1B = 192;
	// set PWM for 75% duty cycle @ 16bit

	TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
	// set none-inverting mode

	TCCR1A |= (1 << WGM10);
	TCCR1B |= (1 << WGM12);//|(1 << WGM13);
	// set Fast PWM mode using ICR1 as TOP
	
	TCCR1B |= (1 << CS10)|(1 << CS12);
	// START the timer with 1024 prescaler
	///////////////////////////////
	OCR2A = 128;
	OCR2B = 128;
	// set PWM for 50% duty cycle


	TCCR2A |= (1 << COM2A1)|(1 << COM2B1);
	// set none-inverting mode

	TCCR2A |= (1 << WGM21) | (1 << WGM20);
	// set fast PWM Mode

	TCCR2B |= (1 << CS20)| (1 << CS21)| (1 << CS22);
	// set prescaler to 1024 and starts PWM
	
	
	//while(1)
	//{
		//TODO:: Please write your application code
	//}
	
}