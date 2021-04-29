#ifndef PROGRAMMING_ASSIGNMENT_5_ECHO_H
#define PROGRAMMING_ASSIGNMENT_5_ECHO_H
#include <utility>
#include "Processor.h"

static const uint8_t ZERO = 128;
static const float SCALE_FACTOR = 0.5f;

class Echo : public Processor {
private:
	int delay;
public:
	explicit Echo(int delay);
	
	void processBuffer(unsigned char *buffer, int bufferSize) override;
};

#endif
