#include "processor.h"
#include "NoiseGate.16Bit.h"


template<typename T>
NoiseGate_16Bit<T>::NoiseGate_16Bit(uint16_t initThreshold){
	threshold = initThreshold;
}
template<typename T>
void NoiseGate_16Bit<T>::processBuffer(T *buffer, int bufferSize){
	uint8_t ZERO_16Bit = 128;
	for(int i = 1; i < bufferSize; i++){
		if(buffer[i] > (ZERO_8Bit - threshold) && buffer[i] < (ZERO_8Bit + threshold))
				buffer[i] = ZERO_8Bit;
				}
			}
			
