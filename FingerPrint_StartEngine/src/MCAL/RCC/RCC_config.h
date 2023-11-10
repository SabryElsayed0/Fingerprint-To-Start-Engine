/******************************************************/
/*      Author  : sabry elsayed                      */

/*      SWC     :   RCC                               */
/*      Date    :   3/9/2023                          */
/*      version :       1.00                          */
/******************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H
/*
    Options :
    1.ENABLE
    2.DISABLE
*/
#define RCC_HSI_ENABLE              ENABLE
#define RCC_HSE_ENABLE              ENABLE
#define RCC_PLL_ENABLE              DISABLE

/*  Options:
            1. RCC_HSI_SELECT
            2. RCC_HSE_SELECT
            3. RCC_PLL_SELECT
            */
#define RCC_CLOCK_SOURCE            RCC_HSI_SELECT





#endif

