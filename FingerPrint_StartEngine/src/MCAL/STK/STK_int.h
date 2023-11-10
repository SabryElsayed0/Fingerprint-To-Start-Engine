/*
 * STK_int.h

 *
 *  Created on: Sep 1, 2022
 *      Author: sabry
 */

#ifndef MCAL_STK_STK_INT_H_
#define MCAL_STK_STK_INT_H_

#define MSTK_SINGLE_INTERVAl    1
#define MSTK_PERIODIC           0

void MSTK_vInit(void);

void MSTK_vStartTimer(u32 A_u32LoadValue);
void MSTK_vStopTimer(void);


void MSTK_vSetBusyWait(u32 A_u32Ticks);

void MSTK_vSetInterval_single(u32 A_u32Ticks, void (*CallbackFunction)(void));
void MSTK_vSetInterval_periodic(u32 A_u32Ticks, void (*CallbackFunction)(void));


u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);




#endif /* MCAL_STK_STK_INT_H_ */
