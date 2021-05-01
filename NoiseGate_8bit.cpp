#include "NoiseGate_8bit_.h"
const uint8_t ZERO = 128;

NoiseGate::NoiseGate(uint8_t initThreshold){
	threshold = initThreshold;
}

void NoiseGate::processBuffer(unsigned char *buffer, int bufferSize, char mono_or_Rstero_or_Lstero){
	if (mono_or_Rstero_or_Lstero == mono){
	
		for(int i = 1; i < bufferSize; i++){
			if(buffer[i] > (ZERO - threshold) && buffer[i] < (ZERO + threshold))
				buffer[i] = ZERO;
				}
			}
			
	else if(mono_or_Rstero_or_Lstero == Rstero){
	
		for(int i = 1; i < bufferSize; i = i + 2){
			if(buffer[i] > (ZERO - threshold) && buffer[i] < (ZERO + threshold))
				buffer[i] = ZERO;
				}
			}
	
	else if(mono_or_Rstero_or_Lstero == Lstero){
	
		for(int i = 2; i < bufferSize; i = i + 2){
			if(buffer[i] > (ZERO - threshold) && buffer[i] < (ZERO + threshold))
				buffer[i] = ZERO;
				}
			}
	
}
