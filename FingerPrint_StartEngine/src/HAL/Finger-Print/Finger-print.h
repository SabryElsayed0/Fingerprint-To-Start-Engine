/*
 * Finger-print.h
 *
 *  Created on: Oct 22, 2023
 *      Author: sabry
 */

#ifndef HAL_FINGER_PRINT_FINGER_PRINT_H_
#define HAL_FINGER_PRINT_FINGER_PRINT_H_
#include "../../LIB/STD_TYPES.h"

//To indicate success condition
#define OK     1
//To indicate fail condition
#define NOK    0
//To indicate user should try agin
#define AGAIN   'G'
//Delay used with finger print module
#define MODULE_DELAY    1000000
#define DELAY           1000


u8 FP_Register(void)        ;
u8 FP_Search (u16 *Id)      ;
#endif /* HAL_FINGER_PRINT_FINGER_PRINT_H_ */
