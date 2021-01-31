/*
 * SPI_private.h
 *
 * Created: 1/30/2021 9:40:57 PM
 *  Author: Mahmoud Amr
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7


//	----------------- PORT B -----------------
#define SPI_DDRB	*((u8*) (0x37))
#define SPI_SPCR	*((volatile u8*) (0x2D))
#define SPI_SPDR	*((volatile u8*) (0x2F)) //SPI Data Register – SPDR


#define SPI_SPSR	*((volatile u8*) (0x2E)) 	//SPI Status Register –SPSR#define SPI_SPIF	7		//• Bit 7 – SPIF: SPI Interrupt Flag

// SPI Control Register – SPCR#define SPI_SPIE	7		//• Bit 7 – SPIE: SPI Interrupt Enable#define SPI_SPE		6		//• Bit 6 – SPE: SPI Enable#define SPI_DORD	5		//• Bit 5 – DORD: Data Order#define SPI_MSTR	4		//• Bit 4 – MSTR: Master/Slave Select#define SPI_CPOL	3		//• Bit 3 – CPOL: Clock Polarity
#define SPI_CPHA	2		//• Bit 2 – CPHA: Clock Phase
#define SPI_SPR1	1		//• Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0
#define SPI_SPR0	0


#endif /* SPI_PRIVATE_H_ */