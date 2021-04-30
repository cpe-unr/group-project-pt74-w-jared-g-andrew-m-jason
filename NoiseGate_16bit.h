#ifndef NOISEGATE_16BIT_H
#define NOISEGATE_16BIT_H
#include "processor.h"
/**
* This is the 16bit NoiseGate class that inherits from the Processor class.
*/
class NoiseGate : public Processor{
	uint16_t threshold;
public:
	/**
	* Constructor for NoiseGate.
	* @param initThreshold - threshold value as unsigned integer with 16bit width
	*/
	NoiseGate(uint16_t initThreshold;
	void processBuffer(short *buffer, int bufferSize);
};


#endif
	
