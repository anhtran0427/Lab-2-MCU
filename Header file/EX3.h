/*
 * EX3.h
 *
 *  Created on: Sep 15, 2024
 *      Author: ASUS
 */

#ifndef INC_EX3_H_
#define INC_EX3_H_
#include "main.h"
#include "EX2.h"
extern const uint8_t MAX_LED;
extern uint8_t index_led ;
extern uint8_t led_buffer [4] ;
void update7SEG ( uint8_t index );
extern void ex3();

#endif /* INC_EX3_H_ */
