/*
 * BIT_MATH.h
 *
 *  Created on: Sep 9, 2023
 *      Author: medo4
 */

#ifndef LIBRARY_BIT_MATH_H_
#define LIBRARY_BIT_MATH_H_

#define		SET_BIT(REG, BIT)	(REG |= (1 << BIT))
#define		CLR_BIT(REG, BIT)	(REG &= ~(1 << BIT))
#define		GET_BIT(REG, BIT)	((REG >> BIT) & 0x01)
#define		TOG_BIT(REG, BIT)	(REG ^= (1 << BIT))


#endif /* LIBRARY_BIT_MATH_H_ */
