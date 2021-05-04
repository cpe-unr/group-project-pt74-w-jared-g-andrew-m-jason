#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <cstdint>
#include <cmath>

template<typename T>
/**
* This is the Processor class. It has one virtual function.
*/
class processor {
public:
       virtual void processBuffer(T* buffer, int bufferSize) = 0;
};


#endif 
