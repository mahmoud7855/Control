#ifndef _UART_CONFIG_H
#define _UART_CONFIG_H

/**UART_Character_SIZE
 * OPTIONS:
 * _5_BIT
 * _6_BIT
 * _7_BIT
 * _8_BIT
 * _9_BIT
*/
#define UART_Character_SIZE        _8_BIT

/**PARITY_MODE
 * OPTIONS:
 * DISABLE
 * ODD_PARITY
 * EVEN_PARITY
*/


#define PARITY_MODE                 DISABLE

/**STOP_BIT_SELECT
 * OPTIONS:
 * _1_BIT
 * _2_BIT
*/

#define STOP_BIT_SELECT             _1_BIT

/**USART_MODE_SELECT
 * OPTIONS:
 * ASYNCHRONOUS
 * SYNCHRONOUS
*/

#define USART_MODE_SELECT           ASYNCHRONOUS

/**BOUD_RATE
 * OPTIONS:
 * ASYNCHRONOUS
 * SYNCHRONOUS
*/

#define BOUD_RATE                   BOUD_9600

/**TRANSMISSION_SPEED
 * OPTIONS:
 * DOUBLE_SPEED
 * NO_DOUBLE_SPEED
*/

#define TRANSMISSION_SPEED          NO_DOUBLE_SPEED

/**TX_CIRCUIT
 * OPTIONS:
 * ENABLE
 * DISABLE
*/
#define TX_CIRCUIT                  ENABLE

/**RX_CIRCUIT
 * OPTIONS:
 * ENABLE
 * DISABLE
*/
#define RX_CIRCUIT                  ENABLE

#endif
