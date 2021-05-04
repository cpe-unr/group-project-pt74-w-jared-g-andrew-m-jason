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
	char list[4], info[4], subChunk[4];
	int size, chunkSize;
	std::string songName, artist;

	int writeSize;
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
//<<<<<<< HEAD
	void writeFile();
//=======
	/**
	* Writes files to a referneced
	* @param fileName - Name of the file as a constant string reference
	*/
	void writeFile(const std::string &outFileName);
	/**
	* Writes files to a referneced
	* @param fileName - Name of the file as a constant string reference
	*/
//>>>>>>> 7f2835a5dc450e3ebadae0ea74021fcbde604d50
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
