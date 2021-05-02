#include <iostream>
#include <fstream>
#include "waveheader.h"
#include <vector>
#include "loadbuffer.h"
#include "filegetter.h"
#include <algorithm>

int main(){
	char buffer;
	
	std::vector<char> characters;
	std::vector<std::string> list;
	std::string metadata;
	short* BitBuffer16;
	wav_header waveHeader;
	std::ifstream file("wavefiles/yes-16-bit-mono.wav", std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*)&waveHeader, sizeof(wav_header));
	}
	if(waveHeader.bit_depth == 16){
		std::cout << "Reading 16 bit audio" << std::endl;
		BitBuffer16 = new short[waveHeader.data_bytes];
        	file.read((char*)BitBuffer16, waveHeader.data_bytes);
		std::getline(file, metadata);
		std::cout << metadata << std::endl;
		
		//while(!file.eof()){
			//if(file >> metadata){
				//list.push_back(metadata);
			//}
			//if(file >> buffer){
			//	if(buffer >= 48 && buffer <= 122){
			//		characters.push_back(buffer);
			//	}
			//	else{
			//		characters.push_back(' ');
			//	}
			//}
		//}
		delete BitBuffer16;
	}
	file.close();
	//for(std::string word : list){
	//	std::cout << word << std::endl;
	//}
	//std::string temp;
	//for(int i = 0; i < metadata.size(); i++){
		//if(metadata[i] >= 48 && metadata[i] <= 122){
		//	temp += metadata[i];
		//}
		//if(metadata[i] != ' ' && metadata[i+1] == ' '){
			//temp += ' ';
		//}
	//}
	
	/*for(int i = 0; i < characters.size(); i++){
		std::string temp;
		if(characters[i] != ' '){
			temp += characters[i];
		}
		if(characters[i] != ' ' && characters[i + 1] == ' '){
			temp += ' ';
		}
		std::cout << temp;
	}*/
	std::cout << (waveHeader.wav_size - waveHeader.data_bytes) << std::endl;
	//std::cout << metadata << std::endl;;
	/*std::string text = "Hello there!";
	
	std::ofstream outfile("text.txt", std::ofstream::binary);
	unsigned int size = text.size();
	outfile.write(reinterpret_cast<char *>(&size), sizeof(size));
	outfile.write(text.c_str(), text.size());
	outfile.close();
	
	size = 0;
	std::ifstream infile("text.txt", std::ifstream::binary);
	infile.read(reinterpret_cast<char *>(&size), sizeof(size));
	std::string buffer;
	buffer.resize(size);
	infile.read(&buffer[0], buffer.size());
	infile.close();
	std::cout << buffer;*/
	/*int userChoice = 10;
	std::string directoryName;
	std::cout << "Enter a directory:" << std::endl;
	std::cin >> directoryName;
	while(userChoice != 0){
		std::cout << "What processing do you want done?" << std::endl;
		std::cout << "0: Exit Program" << std::endl;
		std::cout << "1: Normalization" << std::endl;
		std::cout << "2: Noise Gating" << std::endl;
		std::cout << "3: Echo" << std::endl;
		std::cout << "Enter a number: ";
		std::cin >> userChoice;
		switch(userChoice){
			case 1:
				std::cout << "Applying Normalization\n" << std::endl;
				//processing here
				break;
			case 2:
				std::cout << "Applying Noise Gating\n" << std::endl;
				//processing here
				break;
			case 3:
				std::cout << "Applying Echo\n" << std::endl;
				//processing here
				break;
			case 0:
				std::cout << "Exiting Program" << std::endl;
				break;
			default:
				std::cout << "Please enter a valid number\n" << std::endl;
		}
		
	}
	//a.readFile(fileName);
	//a.writeFile("hello.wav");
	std::string fileName;
	fileGetter a;
	std::vector<std::string> files = a.getFiles(directoryName);
	for(std::string file : files){
		loadBuffer a;
		a.readFile(file);
		a.writeFile();
	}*/
	
	return 0;
}
