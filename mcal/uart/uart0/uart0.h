/*
 * uart0.h
 *
 *  Created on: Aug 16, 2019
 *      Author: New User
 */

#ifndef OMARZAYED_ARM_REPO_MCAL_UART_UART0_UART0_H_
#define OMARZAYED_ARM_REPO_MCAL_UART_UART0_UART0_H_

#include "../../../utils/STD_Types.h"
void UART0_init(void);
uint8 UART0_receive(void);
void UART0_transmit(uint8 WORD);

#endif /* OMARZAYED_ARM_REPO_MCAL_UART_UART0_UART0_H_ */
