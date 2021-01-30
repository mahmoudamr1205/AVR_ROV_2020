#include "../include/uart.h"

void uart_init(void){
		
	UCSRB = (1 << RXEN) | (1 << TXEN);            		  //  enable the transmitter and receiver
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);	  //  select the 8 bit option for the data size
	UBRRL = 103;					  	 	  //  select the baudrate = 9600 for the F_CPU = 16 Mega Hertz 
}

void uart_transmit(uint8_t data){

	while ( !( UCSRA & (1<<UDRE)) );		  //  check the data register is empty first to avoid overwriting the data
	UDR = data;								  //  put the data to the data register to be send
	
}
uint8_t uart_receive(void){

	//while(!(UCSRA & (1<<RXC)));			  //  Wait for the receive to complete
	return UDR;								  //  Return the data received in the data register
	
}
