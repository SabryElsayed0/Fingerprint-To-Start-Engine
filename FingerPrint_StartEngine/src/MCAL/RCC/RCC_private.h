/******************************************************/
/*      Author  : sabry elsayed                      */

/*      SWC     :   RCC                               */
/*      Date    :   3/9/2023                          */
/*      version :       1.00                          */
/******************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H
#define  STD_TYPES_OK        1
#define  STD_TYPES_NOK       0

#define ENABLE          1
#define DISABLE         0

#define RCC_HSI_SELECT      0
#define RCC_HSE_SELECT      1
#define RCC_PLL_SELECT      2

/* CR BITS  */
#define HSION       0
#define HSEON       16
#define CSSON       19
#define HSEBYP      18
/*CFGR BITS*/
#define SW0         0
#define SW1         1




#define RCC_BASE_ADDRESS        0x40023800


typedef struct 
{
    volatile u32     CR             ;
    volatile u32     PLLCFGR        ;
    volatile u32     CFGR           ;
    volatile u32     CIR            ;
    volatile u32     AHB1RSTR       ;
    volatile u32     AHB2RSTR       ;
    volatile u32     RESERVED1      ;
    volatile u32     RESERVED2      ;   
    volatile u32     APB1RSTR       ;
    volatile u32     APB2RSTR       ;
    volatile u32     RESERVED3      ;
    volatile u32     RESERVED4      ;  
    volatile u32     AHB1ENR        ;
    volatile u32     AHB2ENR        ;
    volatile u32     RESERVED5      ;
    volatile u32     RESERVED6      ; 
    volatile u32     APB1ENR        ;
    volatile u32     APB2ENR        ;
    volatile u32     RESERVED7      ;
    volatile u32     RESERVED8      ;
    volatile u32     AHB1LPENR      ;
    volatile u32     AHB2LPENR      ;    
}RCC_MemMap_t;

#define RCC         ((volatile RCC_MemMap_t  *)RCC_BASE_ADDRESS)




#endif

