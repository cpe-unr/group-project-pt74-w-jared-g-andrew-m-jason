#ifndef NORMALIZER_8BIT_H
#define NORMALIZER_8BIT_H
#include "processor.h"

template <class T>
class Normalizer_8Bit : public processor<T>{
public:
	uint8_t MaxValue;
	Normalizer_8Bit(uint16_t initMaxValue);
	void processBuffer(T *buffer, int bufferSize);
};

#endif
