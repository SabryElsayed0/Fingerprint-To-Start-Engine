/******************************************************/
/*      Author  : sabry elsayed                      */

/*      SWC     :   RCC                               */
/*      Date    :   3/9/2023                          */
/*      version :       1.00                          */
/******************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB1            1
#define RCC_APB1            2
#define RCC_APB2            3 
#define RCC_AHB1LP          4
/*  AHB1  Peripherals   */
#define RCC_AHB1_GPIOA          0
#define RCC_AHB1_GPIOB          1
#define RCC_AHB1_GPIOC          2
#define RCC_AHB1_DMA1           21
#define RCC_AHB1_DMA2           22

#define RCC_EN_UART2           17
#define RCC_EN_UART1            4


#define RCC_EN_FMI  15
/*     APB2    Peripherals          */
#define RCC_APB2_SYSCFG          14

void RCC_voidInit   (void);


u8 RCC_u8EnablePeripheralClock      (   u8 Copy_u8BusId    , u8 Copy_u8PerId    );

u8 RCC_u8DisablePeripheralClock     (   u8 Copy_u8BusId    , u8 Copy_u8PerId    );



#endif

