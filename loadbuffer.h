#ifndef LOADBUFFER_H
#define LOADBUFFER_H

#include "waveheader.h"
#include <fstream>
#include <iostream>
#include <string>
/**
* This is the loadBuffer class.
*/
class loadBuffer{
private:
	unsigned char* BitBuffer8 = NULL;
	short* BitBuffer16 = NULL;
	wav_header waveHeader;
public:
	/**
	* Constructor for loadBuffer, does not have any parameters.
	*/
	virtual ~loadBuffer();
	/**
	* Reads files from a constant string reference
	* @param fileName - Name of the file as a constant string reference
	*/
	void readFile(const std::string &fileName);
	/**
	* Writes files to a referneced
	* @param fileName - Name of the file as a constant string reference
	*/
	void writeFile(const std::string &outFileName);
	/**
	* Writes files to a referneced
	* @param fileName - Name of the file as a constant string reference
	*/
	unsigned char* get8Buffer();
	/**
	* Getter for the 16Bit buffer
	*/
	short* get16Buffer();
	/**
	* Getter for the buffer size
	*/
	int getBufferSize();
	/**
	* Getter for the bit depth
	*/
	int getBitDepth();
};

#endif
