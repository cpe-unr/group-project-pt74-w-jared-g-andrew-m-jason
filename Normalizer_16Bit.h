#ifndef NORMALIZER_16BIT_H
#define NORMALIZER_16BIT_H
#include "processor.h"
template <class T>
class Normalizer_16Bit : public processor<T>{
public:
	uint16_t MaxValue;
	Normalizer_16Bit(uint16_t initMaxValue);
	void processBuffer(T *buffer, int bufferSize);
};

#endif
