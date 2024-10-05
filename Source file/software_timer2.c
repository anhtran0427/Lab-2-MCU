/*
 * software_timer.c
 *
 *  Created on: Sep 15, 2024
 *      Author: ASUS
 */
#include "software_timer2.h"

struct pairInformation{
	int index;
	int ms;
};

struct dList{
	struct pairInformation* waitList[10];
	int num;
} List;

uint8_t timerFlag[10]={0};


void setTimer(int index,int ms){
	int temp=ms/TIMER_CYCLE_2;
	if (List.num==0){
		struct pairInformation* entry=malloc(sizeof(struct pairInformation));
		entry->index=index;
		entry->ms=temp;
		List.waitList[0]=entry;
		List.num=1;
	}
	if (List.num!=0){
		int i=0;
		for (;i<List.num;i++){
			if((List.waitList[i])->ms>temp){
				for (int j=List.num-1;j>=i;j--){
					List.waitList[j+1]=List.waitList[j];
				}
				struct pairInformation* entry=malloc(sizeof(struct pairInformation));
				entry->index=index;
				entry->ms=temp;
				List.waitList[i]=entry;
				List.waitList[i+1]->ms=List.waitList[i+1]->ms-temp;
				List.num++;
				break;
			}
			if ((List.waitList[i])->ms<=temp){
				temp=temp-List.waitList[i]->ms;
			}
		}
		if (i==List.num){
			struct pairInformation* entry=malloc(sizeof(struct pairInformation));
			entry->index=index;
			entry->ms=temp;
			List.waitList[List.num]=entry;
			List.num++;
		}

	}
	timerFlag[index] = 0;
}

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	(List.waitList[0]->ms)--;

	int i=0;
	for (;i<List.num;i++){
		if (List.waitList[i]->ms!=0) break;
		timerFlag[(List.waitList[i])->index]=1;
	}
	if (i!=0){
		for (int j=0;j<List.num-i;j++){
			List.waitList[j]=List.waitList[j+i];
		}
		List.num=List.num-i;
	}
 }
