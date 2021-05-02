#include "Normalizer_8Bit.h"
const uint8_t ZERO = 128;
const uint8_t Top = 255;
uint8_t Scale = 0;

NoiseGate::Normalizer(uint8_t initMaxValue){
	MaxValue = initMaxValue;
}

void Normalizer::processBuffer(unsigned char *buffer, int bufferSize){
	
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
