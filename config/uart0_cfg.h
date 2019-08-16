/*
 * uart0_cfg.h
 *
 *  Created on: Aug 16, 2019
 *      Author: New User
 */

#ifndef OMARZAYED_ARM_REPO_CONFIG_UART0_CFG_H_
#define OMARZAYED_ARM_REPO_CONFIG_UART0_CFG_H_

/* Define uart0 baud rate */

#define UART0BaudRate               115200

/* Define uart0 Sysclk */

#define UART0SysClk                 20000000

/* Define uart0 ClkDiv
 * Choose 8 or 16
 *  */

#define UART0ClkDiv                 16

/* Define data length
 * UART05bits
 * UART06bits
 * UART07bits
 * UART08bits
 * */

#define UART0WL                     UART07bits


/* Define No. of stop bits
 * UART0ST1
 * UART0ST2
 *  */

#define UART0SB                     UART0ST1

/* Define whether to use a parity bit
 * UART0NOPARITY
 * UART0ODDPARITY
 * UART0EVENPARITY
 * */

#define UART0PARITY                 UART0NOPARITY



/* Define whether to enable FIFOs
 * DISABLE
 * ENABLE
 * */

#define UART0_ENABLE_FIFOs          DISABLE

/* Define used interrupts */







#endif /* OMARZAYED_ARM_REPO_CONFIG_UART0_CFG_H_ */
