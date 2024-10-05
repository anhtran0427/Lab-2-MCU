/*
 * EX10.c
 *
 *  Created on: Sep 16, 2024
 *      Author: ASUS
 */
#include "EX10.h"
const uint8_t sceneMax=4;
uint8_t sceneNum=0;

uint8_t matrix_scene[][8]={
		{0x00,0x24,0x66,0x24,0x00,0x18,0x24,0x00},
		{0x00,0x24,0x66,0x24,0x00,0x00,0x3C,0x00},
		{0x00,0x24,0x66,0x24,0x00,0x24,0x18,0x00},
		{0x00,0x04,0x46,0x24,0x00,0x24,0x18,0x00}
};
extern void sceneUpdate(){
	if (timerFlag[1]==1){
		for (int i=0;i<8;i++){
				matrix_buffer[i]=matrix_scene[sceneNum][i];
			}
		sceneNum=(sceneNum+1)%sceneMax;
		setTimer(1,50);
	}
	ex9();
}
void sysInit10(){
	sysInit9();
	for (int i=0;i<8;i++){
		matrix_buffer[i]=matrix_scene[0][i];
	}
}
