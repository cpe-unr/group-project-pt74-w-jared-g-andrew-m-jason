#ifndef NORMALIZER_8BIT_H
#define NORMALIZER_8BIT_H
#include "processor.h"

class Normalizer : public Processor{
	uint8_t MaxValue;
public:
	
	Normalizer(uint8_t initMaxValue);
	void processBuffer(unsigned char *buffer, int bufferSize);
};

#endif
