#ifndef NORMALIZER_16BIT_H
#define NORMALIZER_16BIT_H
#include "processor.h"

class Normalizer : public Processor{
	uint16_t MaxValue;
public:
	
	Normalizer(uint16_t initMaxValue);
	void processBuffer(short *buffer, int bufferSize);
};

#endif
