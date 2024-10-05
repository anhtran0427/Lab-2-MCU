/*
 * EX4.c
 *
 *  Created on: Sep 16, 2024
 *      Author: ASUS
 */
#include "EX4.h"

uint8_t counter_4=2;

void ex4(){
	if (timerFlag[0]==1){
		update7SEG((index_led++)%MAX_LED);
		setTimer(0, 250);
	}
	if (timerFlag[1]==1){
		dotDisplay();
		setTimer(1, 1000);
	}
}
