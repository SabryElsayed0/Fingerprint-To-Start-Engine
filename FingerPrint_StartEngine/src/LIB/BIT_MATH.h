/*
 * BIT_MATH.h

 *
 *  Created on: Sep 29, 2023
 *      Author: sabry
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(REG,BITNO) (REG |=  (1<<BITNO))
#define CLR_BIT(REG,BITNO) (REG &= ~(1<<BITNO))
#define TOG_BIT(REG,BITNO) (REG ^= (1<<BITNO) )
#define GET_BIT(REG,BITNO) ((REG >> (BITNO))&1)




#endif /* LIB_BIT_MATH_H_ */
