/*
 * STK_prv.h

 *
 *  Created on: Sep 1, 2022
 *      Author: sabry
 */

#ifndef MCAL_STK_STK_PRV_H_
#define MCAL_STK_STK_PRV_H_

#define STK_AHB				1
#define STK_AHB_DIV_8		2

#define STK_ENABLE  0
#define CLKSOURCE	2
#define TICKINT		1
#define COUNTFLAG	16

#define ENABLE		1
#define DISABLE		0


#define STK_BASE_ADDR			0xE000E010


typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}MSTK_MemMap_t;

#define STK			((volatile MSTK_MemMap_t*)(STK_BASE_ADDR))




#endif /* MCAL_STK_STK_PRV_H_ */
