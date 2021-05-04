#include "Normalizer_8Bit.h"


template<typename T>

Normalizer_8Bit<T>::Normalizer_8Bit(uint8_t initMaxValue){
	MaxValue = initMaxValue;
}
template<typename T>
void Normalizer_8Bit<T>::processBuffer(T *buffer, int bufferSize){
	uint8_t ZERO = 0;
	uint8_t Top = 255;
    	uint8_t Scale = 0;
	
	MaxValue = buffer[0];
   	for(int i=1; i < bufferSize; i++) {
      		if(buffer[i] > MaxValue) {
         		MaxValue = buffer[i];
         		}
         	}
        
        Scale = Top / MaxValue;
         	
	
	for(int i = 1; i < bufferSize; i++){
		buffer[i] = buffer[i] * Scale;
		}
}
