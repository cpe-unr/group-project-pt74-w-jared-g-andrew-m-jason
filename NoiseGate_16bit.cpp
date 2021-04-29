#include "NoiseGate_16Bit_.h"
const uint16_t ZERO = 0;

NoiseGate::NoiseGate(uint16_t initThreshold){
	threshold = initThreshold;
}

void NoiseGate::processBuffer(short *buffer, int bufferSize){
	for(int i = 1; i < bufferSize; i++){
		if(buffer[i] > (ZERO - threshold) && buffer[i] < (ZERO + threshold))
			buffer[i] = ZERO;
		}
}
