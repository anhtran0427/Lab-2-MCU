/*
 * EX2.c
 *
 *  Created on: Sep 15, 2024
 *      Author: ASUS
 */
#include "EX2.h"
uint8_t STATE_2=LED_1;
void seg4Display(){
	switch (STATE_2){
	case LED_1:
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		segDisplay(1);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		STATE_2=LED_2;
		break;
	case LED_2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		segDisplay(2);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		STATE_2=LED_3;
		break;
	case LED_3:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		segDisplay(3);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		STATE_2=LED_4;
		break;
	case LED_4:
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		segDisplay(0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		STATE_2=LED_1;
		break;
	default:
		break;
	}
}

void dotDisplay(){
	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
}

void sysInit2(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, GPIO_PIN_SET);
}
void ex2_run(){
	if (timerFlag[0]==1){
		seg4Display();
		setTimer(0, 500);
	}
	if (timerFlag[1]==1){
		dotDisplay();
		setTimer(1, 1000);
	}
}
