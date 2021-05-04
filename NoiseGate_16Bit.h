#include "NoiseGate_16Bit.h"
const uint16_t ZERO_16Bit = 0;


template<typename T>
NoiseGate_16Bit<T>::NoiseGate_16Bit(uint16_t initThreshold){
threshold = initThreshold;
}
template<typename T>
void NoiseGate_16Bit<T>::processBuffer(T *buffer, int bufferSize){
	for(int i = 1; i < bufferSize; i++){
		if(buffer[i] > (ZERO_16Bit - threshold) && buffer[i] < (ZERO_16Bit + threshold))
			buffer[i] = ZERO_16Bit;
		}
}
