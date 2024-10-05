/*
 * EX1.c
 *
 *  Created on: Sep 15, 2024
 *      Author: ASUS
 */
#include "EX1.h"

uint8_t STATE_1=LED_1;
void seg2Display(){
	switch (STATE_1){
	case LED_1:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		segDisplay(1);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		STATE_1=LED_2;
		break;
	case LED_2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		segDisplay(2);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		STATE_1=LED_1;
		break;
	default:
		break;
	}
}
void ex1_run(){
	if (timerFlag[0]==1){
		seg2Display();
		setTimer(0, 500);
	}
}
