all: test.cpp loadbuffer.o filegetter.o
	g++ -std=c++11 -o audio test.cpp loadbuffer.o filegetter.o

loadbuffer.o: waveheader.h loadbuffer.h loadbuffer.cpp
	g++ -c -std=c++11 loadbuffer.cpp
filegetter.o: filegetter.h filegetter.cpp
	g++ -c -std=c++11 filegetter.cpp

clean:
	rm *.o *.wav audio
