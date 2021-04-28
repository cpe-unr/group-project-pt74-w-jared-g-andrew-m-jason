#include "loadbuffer.h"

loadBuffer::~loadBuffer(){
	if(BitBuffer8 != NULL){
        	delete[] BitBuffer8;
	}
	if(BitBuffer16 != NULL){
		delete[] BitBuffer16;
	}
}	

void loadBuffer::readFile(const std::string &fileName){
	std::ifstream file(fileName,std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*)&waveHeader, sizeof(wav_header));
		std::cout << "Hello" << std::endl;
	}
	if(waveHeader.bit_depth == 8){
		std::cout << "Reading 8 bit audio" << std::endl;
		BitBuffer8 = new unsigned char[waveHeader.data_bytes];
        	file.read((char*)BitBuffer8, waveHeader.data_bytes);
	}
	if(waveHeader.bit_depth == 16){
		std::cout << "Reading 16 bit audio" << std::endl;
		BitBuffer16 = new short[waveHeader.data_bytes];
		file.read((char *)BitBuffer16, waveHeader.data_bytes);
	}
	file.close();
}

void loadBuffer::writeFile(const std::string &outFileName){
	if(waveHeader.bit_depth == 8){
		std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
		outFile.write((char*)&waveHeader,sizeof(wav_header));
		outFile.write((char*)BitBuffer8, waveHeader.data_bytes);
		outFile.close();	
	}
	if(waveHeader.bit_depth == 16){
		std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
		outFile.write((char*)&waveHeader,sizeof(wav_header));
		outFile.write((char*)BitBuffer16, waveHeader.data_bytes);
		outFile.close();	
	}
}

unsigned char* loadBuffer::get8Buffer(){
	return BitBuffer8;
}

short* loadBuffer::get16Buffer(){
	return BitBuffer16;
}

int loadBuffer::getBufferSize(){
	return waveHeader.data_bytes;
}

int loadBuffer::getBitDepth(){
	return waveHeader.bit_depth;
}

