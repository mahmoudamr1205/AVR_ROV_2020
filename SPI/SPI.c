/*
 * SPI.c
 *
 * Created: 1/30/2021 9:31:29 PM
 *  Author: Mahmoud Amr
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"



void SPI_VoidMasterInit(void){
	
	SPI_DDRB|=	(1<<SS)|(1<<MOSI)|(1<<SCK);
	SPI_DDRB&=     ~(1<<MISO);	
	
	/*		The MSB is transmitted first.
	When the DORD bit is written to one, the LSB of the data word is transmitted first.
	When the DORD bit is written to zero, the MSB of the data word is transmitted first.
	*/
	SPI_SPCR  &= ~(1<<SPI_DORD);	
		//Master mode
	SPI_SPCR |=	(1<<SPI_MSTR);
	
		// Enable SPI
	SPI_SPCR |=	(1<<SPI_SPE	);
		
	/*
	Leading Edge:Rising
	written when Rising, read when Falling
	*/
	SPI_SPCR &= ~(1<<SPI_CPOL);
	SPI_SPCR &= ~(1<<SPI_CPHA);
	
	//Shift Clock = CLK /16
	SPI_SPCR &= ~(1<<SPI_SPR1);
	SPI_SPCR |=	(1<<SPI_SPR0);

}


u8 SPI_u8MasterTransmit(u8 Data){
	
	// Start transmission
	SPI_SPDR = Data; 
	
	while((GET_BIT(SPI_SPSR,SPI_SPIF))==0); // Wait for transmission complete
	
	return SPI_SPDR;		// return the received data

}

// Initialize SPI Master Device (with SPI interrupt)
void SPI_voidInt_MasterInit (void){
	
	
}
