#ifndef NOISEGATE_16BIT_H
#define NOISEGATE_16BIT_H
#include "processor.h"

class NoiseGate : public Processor{
	uint16_t threshold;
	
	
public:
	NoiseGate(uint16_t initThreshold;
	void processBuffer(short *buffer, int bufferSize);
};


#endif
	
