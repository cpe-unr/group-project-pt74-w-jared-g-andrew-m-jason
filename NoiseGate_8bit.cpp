#include "NoiseGate_8bit_.h"
const uint8_t ZERO = 128;

NoiseGate::NoiseGate(uint8_t initThreshold){
	threshold = initThreshold;
}

void NoiseGate::processBuffer(unsigned char *buffer, int bufferSize){
	
	for(int i = 1; i < bufferSize; i++){
		if(buffer[i] > (ZERO - threshold) && buffer[i] < (ZERO + threshold))
				buffer[i] = ZERO;
				}
			}
			
	
	
	

