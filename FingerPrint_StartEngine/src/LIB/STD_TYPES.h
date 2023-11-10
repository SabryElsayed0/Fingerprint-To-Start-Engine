/*
 * STD_TYPES.h

 *
 *  Created on: Sep 29, 2023
 *      Author: sabry
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_


typedef unsigned char u8;
typedef  signed  char s8;

typedef unsigned short u16;
typedef signed short   s16;

typedef unsigned long u32;
typedef signed   long s32;

typedef float f32;
typedef  unsigned long long      u64;
typedef  signed   long long      s64;
typedef enum{
	FALSE=0,
	TRUE=1,
	}bool_t;

#define NULL       0
#define NULLPTR    ((void*)0)


#define NULLPTR   ((void*)0)



#endif /* LIB_STD_TYPES_H_ */
