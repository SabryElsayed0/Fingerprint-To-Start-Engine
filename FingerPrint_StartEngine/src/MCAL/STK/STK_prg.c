/*
 * STK_prg.c

 *
 *  Created on: Sep 1, 2022
 *      Author: sabry
 */




#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "STK_int.h"
#include "STK_prv.h"
#include "STK_cfg.h"


static void (*GS_STK_Callback)(void) ;
static u8   G_u8SingleFlag ;



void MSTK_vInit(void)
{
	/* 2- Interrupt enable or disable*/
#if STK_INTERRPUT_EN==ENABLE
	SET_BIT(STK->CTRL, TICKINT) ;
#endif
	/* 1- clock source */
#if STK_CLK_SOURCE == STK_AHB
	SET_BIT(STK->CTRL, CLKSOURCE) ;
#elif STK_CLK_SOURCE == STK_AHB_DIV_8
	CLR_BIT(STK->CTRL , CLKSOURCE);
#endif
}



void MSTK_vStopTimer(void)
{
	CLR_BIT(STK->CTRL , STK_ENABLE );
}


void MSTK_vSetBusyWait(u32 A_u32Ticks)
{
	/* 2- Load timer with Value */
	STK->LOAD = A_u32Ticks ;
	/* 1- reset timer value */
	STK->VAL = 0 ;
	/* 3- Start the timer   */
	SET_BIT(STK->CTRL, STK_ENABLE);
	/* 4-  wait for timer flag to be raised  */
	while(GET_BIT(STK->CTRL, COUNTFLAG) != 1  ){}
	/* 5-  Stop the timer   */
	CLR_BIT(STK->CTRL, STK_ENABLE);
	STK->LOAD = 0;
	STK->VAL  = 0;
}

void MSTK_vSetInterval_single(u32 A_u32Ticks, void (*CallbackFunction)(void))
{
	/* 0- set Callback function */
	GS_STK_Callback = CallbackFunction ;
	G_u8SingleFlag = MSTK_SINGLE_INTERVAl ;
	/*	0-	Enable interrupt	*/
	SET_BIT(STK->CTRL , TICKINT );
	/* 1- reset timer value */
	STK->VAL = 0 ;
	/* 2- Load timer with Value */
	STK->LOAD = A_u32Ticks ;
	/* 3- Start the timer   */
	SET_BIT(STK->CTRL, STK_ENABLE);
}

void MSTK_vSetInterval_periodic(u32 A_u32Ticks, void (*CallbackFunction)(void))
{
	/* 0- set Callback function */
	GS_STK_Callback = CallbackFunction ;
	G_u8SingleFlag = MSTK_PERIODIC ;
	SET_BIT(STK->CTRL , TICKINT );
	/* 1- reset timer value */
	STK->VAL = 0 ;
	/* 2- Load timer with Value */
	STK->LOAD = A_u32Ticks ;
	/* 3- Start the timer   */
	SET_BIT(STK->CTRL, STK_ENABLE);
}


u32  MSTK_u32GetElapsedTime(void)
{
	return (STK->LOAD-STK->VAL) ;
}

u32  MSTK_u32GetRemainingTime(void)
{
	return STK->VAL ;
}

//
//void SysTick_Handler(void)
//{
//	if(GS_STK_Callback != NULL)
//	{
//		GS_STK_Callback();
//	}
//	if(G_u8SingleFlag)
//	{
//		G_u8SingleFlag = 0 ;
//		/* 5-  Stop the timer   */
//		CLR_BIT(STK->CTRL, STK_ENABLE);
//	}
//}


void SysTick_Handler(void)
{


	u8 Local_u8Temporary;
	if(G_u8SingleFlag == MSTK_SINGLE_INTERVAl)
	{
		//disable STK Interrupt
		CLR_BIT(STK->CTRL , TICKINT);

		//Stop Timer
		CLR_BIT(STK->CTRL ,STK_ENABLE );
		STK->LOAD = 0;
		STK->VAL  = 0;
		//
		G_u8SingleFlag = MSTK_PERIODIC;
	}

	if(GS_STK_Callback != NULL)
	{
		GS_STK_Callback();
	}
	//Clear Interrupt flag
 Local_u8Temporary  = GET_BIT(STK->CTRL , COUNTFLAG);
}















