#ifndef NORMALIZER_8BIT_H
#define NORMALIZER_8BIT_H
#include "processor.h"

template <class T>
/**
 * This is the Normalizer (8bit) class that inherits from the Processor class.
*/
class Normalizer_8Bit : public processor<T>{
public:
	uint8_t MaxValue;
	/**
 	* Constructor that takes in maxValue
	* @param initMaxValue - MaxValue for audio as uint8_t
	*/
	Normalizer_8Bit(uint8_t initMaxValue);
	void processBuffer(T *buffer, int bufferSize);
};

#endif
