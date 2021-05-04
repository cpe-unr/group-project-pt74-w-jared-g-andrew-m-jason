#include "Echo_8Bit.h"
#include <iostream>

template<typename T>
void Echo_8Bit<T>::processBuffer(T *buffer, int bufferSize){

	float adj_i;
	float adj_delayed_i;
	float echoLevel = 0.5f;
	float val;
	
	for(int i = 0; i < bufferSize - delay; i++){
		adj_i = (float)(buffer[i] - ZERO);
		adj_delayed_i = (float)(buffer[i + delay] - ZERO);
		val = adj_i * echoLevel + adj_delayed_i * SCALE_FACTOR + ZERO;
		buffer[i + delay] = (T)(round(val));
		}
}
template<typename T>
Echo_8Bit<T>::Echo_8Bit(int delay) : delay(delay) {}
