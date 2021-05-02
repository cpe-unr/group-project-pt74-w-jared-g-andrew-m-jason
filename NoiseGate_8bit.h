#ifndef NOISEGATE_8BIT_H
#define NOISEGATE_8BIT_H
#include "processor.h"
/**
* This is the 8bit NoiseGate class that inherits from the Processor class.
*/
class NoiseGate : public Processor{
	uint8_t threshold;
public:
	/**
	* Constructor for NoiseGate.
	* @param initThreshold - threshold value as unsigned integer with 8bit width
	*/
	NoiseGate(uint8_t initThreshold);
	void processBuffer(unsigned char *buffer, int bufferSize);
};

#endif
	
