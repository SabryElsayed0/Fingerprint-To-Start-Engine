/******************************************************/
/*      Author  : sabry elsayed                      */

/*      SWC     :   RCC                               */
/*      Date    :   3/9/2023                          */
/*      version :       1.00                          */
/******************************************************/
/* LIB  */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInit   (void)
{

	/*  CSS ON  */
	    SET_BIT(RCC->CR , CSSON);
	    /* BYPASS Select    */
	    /*Not Bypass*/
	    CLR_BIT(RCC->CR , HSEBYP);

	    /*  Enable Clock Source */
	    #if     RCC_HSI_ENABLE  ==  ENABLE
	            SET_BIT(RCC->CR , 0);
	    #elif   RCC_HSI_ENABLE  == DISABLE
	            CLR_BIT(RCC->CR , 0 );
	    #endif
	    #if     RCC_HSE_ENABLE  ==  ENABLE
	            SET_BIT(RCC->CR , HSEON);
	    #elif   RCC_HSE_ENABLE  == DISABLE
	            CLR_BIT(RCC->CR , HSEON);
	    #endif

	    /*  Select Clock Source */
	    #if RCC_CLOCK_SOURCE == RCC_HSI_SELECT
	        CLR_BIT( RCC->CFGR , SW0 );
	        CLR_BIT( RCC->CFGR , SW1 );
	    #elif RCC_CLOCK_SOURCE == RCC_HSE_SELECT
	        SET_BIT( RCC->CFGR , SW0 );
	        CLR_BIT( RCC->CFGR , SW1 );
	    #elif RCC_CLOCK_SOURCE == RCC_PLL_SELECT
	        CLR_BIT( RCC->CFGR , SW0 );
	        SET_BIT( RCC->CFGR , SW1 );
	    #endif
	        /*AHB Prescaler / 2 */
	          SET_BIT(RCC->CFGR , 7 );
	/*AHB Prescaler / 8 */
//	CLR_BIT(RCC->CFGR , 4 );
//	SET_BIT(RCC->CFGR , 5 );
//	CLR_BIT(RCC->CFGR , 6 );
//	SET_BIT(RCC->CFGR , 7 );//1010
//	CLR_BIT(RCC->CFGR , 10);
//	CLR_BIT(RCC->CFGR , 11);
//	SET_BIT(RCC->CFGR , 12 );

}

/* AHB1                 ,    GPIOA  */
u8 RCC_u8EnablePeripheralClock      (   u8 Copy_u8BusId    , u8 Copy_u8PerId    )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	if ( (Copy_u8BusId <= RCC_APB2) && (Copy_u8PerId < 32))
	{

		switch(Copy_u8BusId)
		{
		case RCC_AHB1 :
			SET_BIT(RCC->AHB1ENR , Copy_u8PerId );
			break ;
		case RCC_APB1 :
			SET_BIT(RCC->APB1ENR , Copy_u8PerId);
			break ;
		case RCC_APB2 :
			SET_BIT(RCC->APB2ENR , Copy_u8PerId);
			break ;
		case RCC_AHB1LP :
			SET_BIT(RCC->AHB1LPENR ,Copy_u8PerId);
			break ;

		default :
			Local_u8ErrorState = STD_TYPES_NOK ;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

u8 RCC_u8DisablePeripheralClock     (   u8 Copy_u8BusId    , u8 Copy_u8PerId    )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	if ( (Copy_u8BusId <= RCC_APB2) && (Copy_u8PerId < 32))
	{

		switch(Copy_u8BusId)
		{
		case RCC_AHB1 :
			CLR_BIT(RCC->AHB1ENR , Copy_u8PerId );
			break ;
		case RCC_APB1 :
			CLR_BIT(RCC->APB1ENR , Copy_u8PerId);
			break ;
		case RCC_APB2 :
			CLR_BIT(RCC->APB2ENR , Copy_u8PerId);
			break ;

		default :
			Local_u8ErrorState = STD_TYPES_NOK ;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState ;
}

