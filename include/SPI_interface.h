/*
 * SPI_interface.h
 *
 * Created: 1/30/2021 9:39:41 PM
 *  Author: Mahmoud Amr
 */ 


#include "STD_TYPES.h"


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_VoidMasterInit(void);


u8 SPI_u8MasterTransmit(u8 Data);

// Initialize SPI Master Device (with SPI interrupt)
void SPI_voidInt_MasterInit (void);

#endif /* SPI_INTERFACE_H_ */