/*
 * NVIC_private.h

 *
 *  Created on: Aug 30, 2023
 *      Author: First
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_


#define NVIC_BASE_ADDRESS	0xE000E100

#define VECT_KEY	0x05FA0000

typedef struct
{

	volatile u32 ISER[32] 	;
	volatile u32 ICER[32]	;
	volatile u32 ISPR[32]	;
	volatile u32 ICPR[32]	;
	volatile u32 IAPR[32]	;
	volatile u32 RESERVED[32];
	volatile u8 IPR[128]		;

}NVIC_MemMap_t;

#define NVIC	((volatile NVIC_MemMap_t *)NVIC_BASE_ADDRESS)


/*========================================================*/

#define SCB_BASE_ADDRESS	0xE000ED00

typedef struct
{
	volatile u32 CPUID	;
	volatile u32 ICSR	;
	volatile u32 VTOR	;
	volatile u32	AIRCR	;
	volatile u32 SCR		;
	volatile u32 CCR		;
	volatile u32 SHPR1	;
	volatile u32 SHPR2	;
	volatile u32 SHPR3	;
	volatile u32 SHCSR	;
	volatile u32 CFSR	;
	volatile u32 HFSR	;
	volatile u32 MMAR	;
	volatile u32 BFAR	;
	volatile u32 AFSR	;
}SCB_MemMap_t;

#define SCB		((volatile SCB_MemMap_t *)SCB_BASE_ADDRESS)

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
