#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>
#include <cmath>
template<typename T>
class processor {
public:
       virtual void processBuffer(T* buffer, int bufferSize) = 0;
};


#endif 
