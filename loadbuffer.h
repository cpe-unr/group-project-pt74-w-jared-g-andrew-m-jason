#ifndef LOADBUFFER_H
#define LOADBUFFER_H

#include "waveheader.h"
#include <fstream>
#include <iostream>
#include <string>

class loadBuffer{
private:
	unsigned char* BitBuffer8 = NULL;
	short* BitBuffer16 = NULL;
	wav_header waveHeader;
public:
	virtual ~loadBuffer();
	
	void readFile(const std::string &fileName);
	void writeFile(const std::string &outFileName);
	unsigned char* get8Buffer();
	short* get16Buffer();
	int getBufferSize();
	int getBitDepth();
};

#endif
