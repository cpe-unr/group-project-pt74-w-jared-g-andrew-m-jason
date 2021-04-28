all: loadwav.cpp loadbuffer.o
	g++ -std=c++11 -o audio loadwav.cpp loadbuffer.o

loadbuffer.o: waveheader.h loadbuffer.h loadbuffer.cpp
	g++ -c -std=c++11 loadbuffer.cpp

clean:
	rm *.o audio
