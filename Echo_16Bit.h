#ifndef PROGRAMMING_ASSIGNMENT_5_ECHO_16Bit_H
#define PROGRAMMING_ASSIGNMENT_5_ECHO_16Bit_H
#include <utility>
#include "Processor.h"

static const uint16_t ZERO = 0;
static const float SCALE_FACTOR = 0.5f;
/**
 * This is the Echo class that inherits from the Processor class.
*/
class Echo : public Processor {
private:
	int delay;
public:
	/** 
	* Constructor that takes in the delay foor the Echo
	* @param delay - delay rate as an integer
	*/
	explicit Echo(int delay);
	/**
	* Overrides the processBuffer function
	*/
	void processBuffer(short *buffer, int bufferSize) override;
};

#endif
