#include "Normalizer_16Bit.h"
const uint16_t ZERO = 0;
const uint16_t Top = 32768;
uint16_t Scale = 0;

NoiseGate::Normalizer(uint16_t initMaxValue){
	MaxValue = initMaxValue;
}

void Normalizer::processBuffer(short *buffer, int bufferSize){
	
	MaxValue = buffer[0];
   	for(i=1; i < bufferSize; i++) {
      		if(buffer[i] > MaxValue) {
         		MaxValue = buffer[i];
         		}
         	}
        
        Scale = Top / MaxValue;
         	
	
	for(int i = 1; i < bufferSize; i++){
		buffer[i] = buffer[i] * Scale;
		}
}
