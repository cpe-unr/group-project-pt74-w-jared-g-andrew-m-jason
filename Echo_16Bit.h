#ifndef ECHO_16Bit_H
#define ECHO_16Bit_H
#include <utility>
#include "processor.h"



/**
 * This is the Echo class that inherits from the Processor class.
*/
template <class T>

class Echo_16Bit : public processor<T> {
private:
	int delay;
public:
	/** 
	* Constructor that takes in the delay foor the Echo
	* @param delay - delay rate as an integer
	*/
	explicit Echo_16Bit(int delay);
	/**
	* Overrides the processBuffer function
	*/
	void processBuffer(T *buffer, int bufferSize) override;
	 uint16_t ZERO = 0;
	 float SCALE_FACTOR = 0.5f;
};

#endif

