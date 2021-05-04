
#include "NoiseGate_8Bit.h"
#include "processor.h"

    
const uint8_t ZERO_8Bit = 128;
template<typename T>
NoiseGate_8Bit<T>::NoiseGate_8Bit(uint8_t initThreshold){
	threshold = initThreshold;
}
template<typename T>
void NoiseGate_8Bit<T>::processBuffer(T *buffer, int bufferSize){
	
	for(int i = 1; i < bufferSize; i++){
		if(buffer[i] > (ZERO_8Bit - threshold) && buffer[i] < (ZERO_8Bit + threshold))
				buffer[i] = ZERO_8Bit;
				}
			}
			
	
	

