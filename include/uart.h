/*
	Please note that this driver is working for ATMEGA 32 
	The AVR 8 bits family has the same architecture so,
	If you want to change the microcontroller check the register addresses for the needed microcontroller
	and change the addresses below
*/


#ifndef UART_H_
#define UART_H_



/*
	Define the cpu to 16 megahertz.
	Please note that the changing in cpu frequency will request to change the baudrate 
*/
#ifndef F_CPU
#define F_CPU 16000000UL
#endif






/*
	The following registers used to set control and get status of the USART 
*/
#define UCSRA (*(volatile uint8_t *) 0x2B)
#define UCSRB (*(volatile uint8_t *) 0x2A)
#define UCSRC (*(volatile uint8_t *) 0x40)



/*
	This register is to set the baudrate of the communication
*/
#define UBRRL (*(volatile uint8_t * ) 0x29)



/*
	This is the data register, the same register is used to send and receive
*/
#define UDR (*(volatile uint8_t * ) 0x2C)




/*
	TXEN and RXEN bits are used to enable transmitter and receiver to use uart 
	You can find the two bits in the UCSRB register
*/
#define TXEN 3
#define RXEN 4




/*
	UCSZ bits are used to select the size of data to be send or received
	you can find UCSZ0 and UCSZ1 in UCSRC register, UCSZ2 in UCSRB register

	bits / UCSZ      2     1     0
	
	5	    	  	 0     0     0
	6				 0	   0     1
	7				 0     1     0
	8                0     1     1
	9                1     1     1
*/
#define UCSZ0 1 
#define UCSZ1 2
#define UCSZ2 2


/*
	This bit in UCSRC register must be 1 to write to UCSRC
*/
#define URSEL 7

/*
	RXC is a flag set by the hardware, we check on it to know if the receive complete or not
	You can found this bit in UCSRA register

	UDRE is a flag set by the hardware, check to know if the Uart data regiser is empty or not
	You can found this bit in UCSRA register
*/
#define RXC 7
#define UDRE 5 




/*
	This function is used to set the initilazation needed to configure the uart communication protocol

	@param it takes no parameters

	@return void return nothing

*/
void uart_init(void);



/*
	This function used to transmit the data

	@param data it is unsigned char variable which holds the data to be send

	@return void return nothing
*/
void uart_transmit(uint8_t data);



/*
	This function is used to receive the data.

	@param void it takes no parameters

	@return data unsigned char value will be returned, it is the received data
*/
uint8_t uart_receive(void);




#endif /* UART_H_ */
