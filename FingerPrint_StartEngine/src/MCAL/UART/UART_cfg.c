

#include "UART_cfg.h"

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "UART_int.h"
/*
 * BaudRate
 * Bluetooth    9600
 * WIFI         115200
 */
USART_InitType uart1_cfg =
{
		.BaudRate           = 9600,
		.DataWidth          = USART_MODE_8BIT,
		.StopBits           = USART_STOP_BIT_1,
		.Parity_Enable      = DISABLE,
		.Parity_Selection   = USART_EVEN_PARITY,
		.TransferDirection  = USART_TX_RX,
		.Oversampling       = USART_OVER_SAMPLING_8

};
USART_InitType uart2_cfg =
{
		.BaudRate           = 9600,
		.DataWidth          = USART_MODE_8BIT,
		.StopBits           = USART_STOP_BIT_1,
		.Parity_Enable      = DISABLE,
		.Parity_Selection   = USART_EVEN_PARITY,
		.TransferDirection  = USART_TX_RX,
		.Oversampling       = USART_OVER_SAMPLING_8

};
USART_InitType uart6_cfg =
{
		.BaudRate           = 115200,
		.DataWidth          = USART_MODE_8BIT,
		.StopBits           = USART_STOP_BIT_1,
		.Parity_Enable      = DISABLE,
		.Parity_Selection   = USART_EVEN_PARITY,
		.TransferDirection  = USART_TX_RX,
		.Oversampling       = USART_OVER_SAMPLING_8

};
#ifdef __UART2__
GPIO_PinConfig uart_pinTx =
{
		.Port = GPIO_PORTA,
		.Pin  = GPIO_PIN2 ,
		.Mode = GPIO_MODE_ALTERNATIVE,
		.OutputSpeed = GPIO_OUTPUT_SPEED_MEDIUM,
		.OutputType = GPIO_OUTPUT_PUSH_PULL,
		.alt_func = 7,
};
GPIO_PinConfig uart_pinRx =
{
		.Port = GPIO_PORTA,
		.Pin  = GPIO_PIN3 ,
		.Mode = GPIO_MODE_ALTERNATIVE,
		.OutputSpeed = GPIO_OUTPUT_SPEED_MEDIUM,
		.PullState = GPIO_NO_PULL,
		//.OutputType = GPIO_OUTPUT_PUSH_PULL,
		.alt_func = 7,
};
#endif
#ifdef __UART1__
GPIO_PinConfig uart_pinTx1 =
{
		.Port = GPIO_PORTA,
		.Pin  = GPIO_PIN9 ,
		.Mode = GPIO_MODE_ALTERNATIVE,
		.OutputSpeed = GPIO_OUTPUT_SPEED_MEDIUM,
		.OutputType = GPIO_OUTPUT_PUSH_PULL,
		.alt_func = 7,
};

GPIO_PinConfig uart_pinRx1 =
{
		.Port = GPIO_PORTA,
		.Pin  = GPIO_PIN10 ,
		.Mode = GPIO_MODE_ALTERNATIVE,
		.OutputSpeed = GPIO_OUTPUT_SPEED_MEDIUM,
		.PullState = GPIO_NO_PULL,
		//.OutputType = GPIO_OUTPUT_PUSH_PULL,
		.alt_func = 7,
};
#endif
