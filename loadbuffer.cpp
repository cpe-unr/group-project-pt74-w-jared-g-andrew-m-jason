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
	std::ifstream file(fileName, std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*)&waveHeader, sizeof(wav_header));
	}
	if(waveHeader.bit_depth == 8){
		std::cout << "Reading 8 bit audio" << std::endl;
		BitBuffer8 = new unsigned char[waveHeader.data_bytes];
        	file.read((char*)BitBuffer8, waveHeader.data_bytes);
		file.read((char*)list, sizeof(list));
		file.read((char*)&size, sizeof(size));
		file.read((char*)info, sizeof(info));
		while(!file.eof()){
			std::cout << "test";
			file.read((char*)subChunk, sizeof(subChunk));
			file.read((char*)&chunkSize, sizeof(chunkSize));
			char temp[chunkSize];
			file.read((char*)temp, sizeof(temp));
			if(subChunk[0] == 'I'){
				if(subChunk[1] == 'N'){
					std::cout << "Song Name: ";
					std::cout << temp << std::endl;
				}
				if(subChunk[1] == 'A'){
					std::cout << "Artist: ";
					std::cout << temp << std::endl;
				}
			}
		}
	}
	if(waveHeader.bit_depth == 16){
		std::cout << "Reading 16 bit audio" << std::endl;
		BitBuffer16 = new short[waveHeader.data_bytes];
		file.read((char *)BitBuffer16, waveHeader.data_bytes);
		file.read((char*)list, sizeof(list));
		file.read((char*)&size, sizeof(size));
		file.read((char*)info, sizeof(info));
		while(!file.eof()){
			file.read((char*)subChunk, sizeof(subChunk));
			file.read((char*)&chunkSize, sizeof(chunkSize));
			char temp[chunkSize];
			file.read((char*)temp, sizeof(temp));
			if(subChunk[0] == 'I'){
				if(subChunk[1] == 'N'){
					std::cout << "Song Name: ";
					songName = temp;
					std::cout << songName << std::endl;
				}
				if(subChunk[1] == 'A'){
					std::cout << "Artist: ";
					artist = temp;
					std::cout << artist << std::endl;
				}
			}
		}
		
	}
	file.close();
}

void loadBuffer::writeFile(){
	if(waveHeader.bit_depth == 8){
		std::string outFileName;
		std::cout << "Enter a name for the new file: ";
		std::cin >> outFileName;
		std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
		outFile.write((char*)&waveHeader,sizeof(wav_header));
		outFile.write((char*)BitBuffer8, waveHeader.data_bytes);
		outFile.close();	
	}
	if(waveHeader.bit_depth == 16){
		std::string outFileName;
		std::cout << "Enter a name for the new file: ";
		std::cin >> outFileName;
		std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
		outFile.write((char*)&waveHeader,sizeof(wav_header));
		outFile.write((char*)BitBuffer16, waveHeader.data_bytes);
		
		/*std::string writeString = "LIST";
		outFile.write((char*)&writeString[0], writeString.size());
		writeSize = 0;
		outFile.write((char*)&writeSize, sizeof(writeSize));
		writeString = "INFO";
		outFile.write((char*)&writeString[0], writeString.size());
		
		
		writeString = "INAM";
		writeSize = songName.size();
		outFile.write((char*)&writeString[0], writeString.size());
		outFile.write((char*)&writeSize, songName.size());
		outFile.write(songName.c_str(), songName.size());
		
		writeString = "IART";
		writeSize = artist.size();
		outFile.write((char*)&writeString[0], writeString.size());
		outFile.write((char*)&writeSize, artist.size());
		outFile.write(artist.c_str(), artist.size());
		outFile.close();*/	
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

