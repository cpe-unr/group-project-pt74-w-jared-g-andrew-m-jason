#ifndef NOISEGATE_8BIT_H
#define NOISEGATE_8BIT_H
#include "processor.h"
/**
* This is the 8bit NoiseGate class that inherits from the Processor class.
*/
template <class T>
class NoiseGate_8Bit : public processor<T>{
	uint8_t threshold;
public:
	/**
	* Constructor for NoiseGate.
	* @param initThreshold - threshold value as unsigned integer with 8bit width
	*/
	NoiseGate_8Bit(uint8_t initThreshold);
	
	
	void processBuffer(T *buffer, int bufferSize);
};

#endif
	
