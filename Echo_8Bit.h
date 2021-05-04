#ifndef ECHO_8Bit_H
#define ECHO_8Bit_H
#include <utility>
#include "processor.h"



/**
 * This is the Echo class that inherits from the Processor class.
*/
template <class T>

class Echo_8Bit : public processor<T> {
private:
	int delay;
public:
	/** 
	* Constructor that takes in the delay foor the Echo
	* @param delay - delay rate as an integer
	*/
	explicit Echo_8Bit(int delay);
	/**
	* Overrides the processBuffer function
	*/
	void processBuffer(T *buffer, int bufferSize) override;
	 uint8_t ZERO = 128;
	 float SCALE_FACTOR = 0.5f;
};

#endif

