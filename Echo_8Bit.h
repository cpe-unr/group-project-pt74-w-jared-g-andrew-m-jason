#ifndef PROGRAMMING_ASSIGNMENT_5_ECHO_8Bit_H
#define PROGRAMMING_ASSIGNMENT_5_ECHO_8Bit_H
#include <utility>
#include "Processor.h"

static const uint8_t ZERO = 128;
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
	void processBuffer(unsigned char *buffer, int bufferSize) override;
};

#endif
