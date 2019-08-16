/*
 * Port_hw.h
 *
 *  Created on: Jul 23, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_
#define E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_

#include "../utils/STD_Types.h"

typedef struct
{
    uint32 GPIODATA    ;
    uint32 GPIODIR     ;
    uint32 GPIOIS      ;
    uint32 GPIOIBE     ;
    uint32 GPIOIEV     ;
    uint32 GPIOIM      ;
    uint32 GPIORIS     ;
    uint32 GPIOMIS     ;
    uint32 GPIOICR     ;
    uint32 GPIOAFSEL   ; /*offset : 0x420 -> 424 */

    uint8 Reserved_2[0xDC];
    uint32 GPIODR2R    ; /*offset : 0x500 */
    uint32 GPIODR4R    ;
    uint32 GPIODR8R    ;
    uint32 GPIOODR     ;
    uint32 GPIOPUR     ;
    uint32 GPIOPDR     ;
    uint32 GPIOSLR     ;
    uint32 GPIODEN     ;
    uint32 GPIOLOCK    ;
    uint32 GPIOCR      ;
    uint32 GPIOAMSEL   ;
    uint32 GPIOPCTL    ;
    uint32 GPIOADCCTL  ;
    uint32 GPIODMACTL  ;

}PORT_RegType;

#define PORTA_REG     (*((volatile PORT_RegType*)0x400043FC))
#define PORTB_REG     (*((volatile PORT_RegType*)0x400053FC))
#define PORTC_REG     (*((volatile PORT_RegType*)0x400063FC))
#define PORTD_REG     (*((volatile PORT_RegType*)0x400073FC))
#define PORTE_REG     (*((volatile PORT_RegType*)0x400243FC))
#define PORTF_REG     (*((volatile PORT_RegType*)0x400253FC))




typedef struct
{
    uint32 UARTDR           ;
    uint32 UARTRSR_UARTECR  ;
    uint8  Reserved_3[0x14] ;
    uint16 UARTFR           ;
    uint32 UARTILPR         ;
    uint32 UARTIBRD         ;
    uint32 UARTFBRD         ;
    uint32 UARTLCRH         ;
    uint32 UARTCTL          ;
    uint32 UARTIFLS         ;
    uint32 UARTIM           ;
    uint32 UARTRIS          ;
    uint32 UARTMIS          ;
    uint32 UARTICR          ;
    uint32 UARTDMACTL       ;
    uint8  Reserved_4[0x58] ;
    uint32 UART9BITADDR     ;
    uint32 UART9BITAMASK    ;
    uint8  Reserved_5[0xF14];
    uint32 UARTPP           ;
    uint32 UARTCC           ;
    uint8  Reserved_6[0x4]  ;
    uint32 UARTPeriphID4    ;
    uint32 UARTPeriphID5    ;
    uint32 UARTPeriphID6    ;
    uint32 UARTPeriphID7    ;
    uint32 UARTPeriphID0    ;
    uint32 UARTPeriphID1    ;
    uint32 UARTPeriphID2    ;
    uint32 UARTPeriphID3    ;
    uint32 UARTPCellID0     ;
    uint32 UARTPCellID1     ;
    uint32 UARTPCellID2     ;
    uint32 UARTPCellID3     ;

}UART_RegType;

#define UART0_REG      (*((volatile UART_RegType*)0x4000C000))
#define UART1_REG      (*((volatile UART_RegType*)0x4000D000))
#define UART2_REG      (*((volatile UART_RegType*)0x4000E000))
#define UART3_REG      (*((volatile UART_RegType*)0x4000F000))
#define UART4_REG      (*((volatile UART_RegType*)0x40010000))
#define UART5_REG      (*((volatile UART_RegType*)0x40011000))
#define UART6_REG      (*((volatile UART_RegType*)0x40012000))
#define UART7_REG      (*((volatile UART_RegType*)0x40013000))

#define RCGCGPIO_REG    (*((volatile uint32*)0x400FE608))
#define RCGCUART_REG    (*((volatile uint32*)0x400FE618))

#endif /* E15_ARM_REPO_MCAL_PORT_DRIVER_PORT_HW_H_ */
