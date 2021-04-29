#ifndef NOISEGATE_8BIT_H
#define NOISEGATE_8BIT_H
#include "processor.h"

class NoiseGate : public Processor{
	uint8_t threshold;
	
	
public:
	NoiseGate(uint8_t initThreshold);
	void processBuffer(unsigned char *buffer, int bufferSize);
};


#endif
	
