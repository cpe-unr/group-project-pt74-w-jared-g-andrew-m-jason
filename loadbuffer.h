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
	std::string songName, artist, writeString;

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
	* Writes CSV file containing metadata
	* @param filename - Name of file as a constant string reference
	* @param songTitle - Name of song title as a string
	* @param artist - Name of artist as a string
	*/
	void writeCSV(const std::string &fileName, std::string songTitle, std::string artist);
	/**
	* Getter for the 8bit buffer
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
	/**
	* Getter for the artist
	*/
	std::string getArtist();
	/**
	* Setter for the artist
	*/	
	void setArtist(std::string newArtist);
	/**
	* Getter for the song name
	*/
	std::string getSongName();
	/**
	* Setter for the song name
	*/
	void setSongName(std::string newSongName);
};

#endif
