/*
 * uart0.c
 *
 *  Created on: Aug 16, 2019
 *      Author: New User
 */

#include "OmarZayed_arm_repo/utils/STD_Types.h"
#include "OmarZayed_arm_repo/utils/Bit_Math.h"
#include "OmarZayed_arm_repo/mcal/mcu_hw.h"
#include "../../../config/uart0_cfg.h"
#include "../../mcu_hw.h"
#include "uart0.h"

#define UART0WLmsk                         0b10011111
#define UART05bits                         0b00000000
#define UART06bits                         0b00100000
#define UART07bits                         0b01000000
#define UART08bits                         0b01100000

#define UART0ST1                           0
#define UART0ST2                           1

#define UART0PARITYmsk                     0b11111001
#define UART0NOPARITY                      0b00000000
#define UART0ODDPARITY                     0b00000010
#define UART0EVENPARITY                    0b00000110


static void UART0_BRD(void);
static uint32 DecToBinary(uint32 DecValue);
static uint32 UINT0DIVINT;
static uint32 UINT0DIVFRAC;


void UART0_init(void)
{
    // Setting RCGCUART_REG

    SET_BIT(RCGCUART_REG,0);    // What if ((uint8)1)?


    // Setting RCGCGPIO_REG

    SET_BIT(RCGCGPIO_REG,5);    // U1RTS?

    // Calculate BDR (Also this step will make the delay of 3 clk cycles needed before writing in any UART reg

    UART0_BRD();


    // Steps 3, 4 and 5 are made by the port (Revise).




    //  1. Disable the UART by clearing the UARTEN bit in the UARTCTL register.

    CLR_BIT(UART0_REG.UARTCTL,0);


    // 2. Write the integer portion of the BRD to the UARTIBRD register.

    UART0_REG.UARTIBRD = UINT0DIVINT;

    // 3. Write the fractional portion of the BRD to the UARTFBRD register.

    UART0_REG.UARTFBRD = UINT0DIVFRAC;

    // 4. Write the desired serial parameters to the UARTLCRH register (in this case, a value of 0x0000.0060).

        // 4.1 Write Word Length

        UART0_REG.UARTLCRH &= UART0WLmsk;
        UART0_REG.UARTLCRH |= UART0WL;

        // 4.2 Write Stop Bit

        if(UART0SB)
        {
            SET_BIT(UART0_REG.UARTLCRH,3);
        }
        else
        {
            CLR_BIT(UART0_REG.UARTLCRH,3);
        }

        // 4.3 Parity

        UART0_REG.UARTLCRH &= UART0PARITYmsk;
        UART0_REG.UARTLCRH |= UART0PARITY;

        // 4.4 FIFOs

        if(UART0_ENABLE_FIFOs)
        {
            SET_BIT(UART0_REG.UARTLCRH,4);
        }
        else
        {
            CLR_BIT(UART0_REG.UARTLCRH,4);
        }

    //  7. Enable the UART by setting the UARTEN bit in the UARTCTL register.

        SET_BIT(UART0_REG.UARTCTL,0);


}

uint8 UART0_receive(void)
{
    return UART0_REG.UARTDR;
}

void UART0_transmit(uint8 WORD)
{
    UART0_REG.UARTDR = WORD;
}


static void UART0_BRD(void)
{
    // Setting baud-rate divisor

    float32 UART0_BRD = UART0SysClk / (UART0SysClk * UART0BaudRate);


    // Getting baud-rate divisor integer part

    uint32 UART0_BRDI = (uint32)UART0_BRD;


    // Getting baud-rate divisor decimal part

    float32 UART0_BRDF = UART0_BRD - UART0_BRDI;


    // Getting baud-rate divisor decimal part reg value

    uint32 UART0FBRD = (UART0_BRDF * 64) + 0.5;

    UINT0DIVINT = DecToBinary(UART0_BRDI);
    UINT0DIVFRAC = DecToBinary(UART0FBRD);


}

static uint32 DecToBinary(uint32 DecValue)
{
    // array to store binary number
    uint8 binaryNum[32];

    // out value
    uint32 outValue = 0;

    uint8 j;

    // counter for binary array
    uint8 i = 0;
    while (DecValue)
    {
        // storing remainder in binary array
        binaryNum[i] = DecValue % 2;
        DecValue /= 2;
        i++;
    }

    // printing binary array in reverse order
    for (j = i - 1; j >= 0; j--)
    {
        if(binaryNum[j])
        {
            SET_BIT(outValue,j);
        }
    }

    return outValue;

}



