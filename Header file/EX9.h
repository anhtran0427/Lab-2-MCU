/*
 * EX9.h
 *
 *  Created on: Sep 16, 2024
 *      Author: ASUS
 */

#ifndef INC_EX9_H_
#define INC_EX9_H_

#include "main.h"
extern uint8_t matrix_buffer [8];


extern void updateLEDMatrix (int index );
extern void rowDisplay(uint8_t num);
extern void colReset();
extern void rowReset();
extern void ex9();
extern void sysInit9();
#endif /* INC_EX9_H_ */
