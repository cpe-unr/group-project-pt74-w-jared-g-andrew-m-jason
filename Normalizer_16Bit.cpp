#include "Normalizer_16Bit.h"


template<typename T>

Normalizer_16Bit<T>::Normalizer_16Bit(uint16_t initMaxValue){
	MaxValue = initMaxValue;
}
template<typename T>
void Normalizer_16Bit<T>::processBuffer(T *buffer, int bufferSize){
	uint16_t ZERO = 0;
	uint16_t Top = 32768;
    uint16_t Scale = 0;
	
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
