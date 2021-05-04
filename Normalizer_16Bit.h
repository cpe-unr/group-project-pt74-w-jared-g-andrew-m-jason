#ifndef NORMALIZER_16BIT_H
#define NORMALIZER_16BIT_H

#include "processor.h"
template <class T>
/**
 * This is the Normalizer (16bit) class that inherits from the Processor class.
*/
class Normalizer_16Bit : public processor<T>{
public:
	uint16_t MaxValue;
	/**
 	* Constructor that takes in maxValue
	* @param initMaxValue - MaxValue for audio as uint16_t
	*/
	Normalizer_16Bit(uint16_t initMaxValue);
	void processBuffer(T *buffer, int bufferSize);
};

#endif
