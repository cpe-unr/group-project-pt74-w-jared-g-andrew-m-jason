#include "Echo.h"
#include <iostream>

void Echo::processBuffer(short *buffer, int bufferSize){

	float adj_n;
	float adj_delayed;
	float echoLevel = 0.5f;
	float val;
	
	for(int i = 0; i < bufferSize - delay; i++){
		adj_n = (float)(buffer[i] - ZERO);
		adj_delayed_n = (float)(buffer[n + delay] - ZERO);
		val = adj_n * echoLevel + adj_deleayed_n * SCALE_FACTOR + ZERO;
		buffer[n + delay] = (short char)(round(val));
		}
}

Echo::Echo(int delay) : delay(delay) {}
