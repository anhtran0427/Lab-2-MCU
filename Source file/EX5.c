/*
 * EX5.c
 *
 *  Created on: Sep 16, 2024
 *      Author: ASUS
 */

#include "EX5.h"
uint8_t hr = 15 , min = 8 , sec = 50;

void ex5(){
	if (timerFlag[2]==1){
		sec++;
		if (sec>=60){
			sec=0;
			min++;
		}
		if (min>=60){
			min=0;
			hr++;
		}
		if (hr>=24){
			hr=0;
		}
		updateClockBuffer();
		setTimer(2, 1000);
	}
	ex4();

}
void updateClockBuffer(){
	led_buffer[0]=hr/10;
	led_buffer[1]=hr%10;
	led_buffer[2]=min/10;
	led_buffer[3]=min%10;
}
void sysInit5(){
	led_buffer[0]=1;
	led_buffer[1]=5;
	led_buffer[2]=0;
	led_buffer[3]=8;
	sysInit2();
}
