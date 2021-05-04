#include <iostream>
#include <fstream>
#include "waveheader.h"
#include <vector>
#include "loadbuffer.h"
#include "filegetter.h"
#include "Echo_16Bit.h"
#include "Echo_8Bit.h"
#include "processor.h"
#include <algorithm>

int main(){
	int userChoice = 10;
	char userInput;
	std::string artist, songName;
	std::string directoryName;
	fileGetter a;
	
	std::cout << "Enter a directory:" << std::endl;
	
	std::cin >> directoryName;
	std::vector<std::string> files = a.getFiles(directoryName);
	
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
				for(std::string file : files){
					loadBuffer a;
					a.readFile(file);
					if(a.getBitDepth() == 16 || a.getBitDepth() == 8){
						std::cout << "Would you like to change the metadata? Y/N" << std::endl;
						std::cin >> userInput;
						if(userInput == 'Y'){
							std::cout << "Enter new song name: ";
							std::cin >> songName;
							a.setSongName(songName);
							std::cout << "Enter new artist name: ";
							std::cin >> artist;
							a.setArtist(artist);
							
						}
						if(a.getBitDepth() == 16){
							processor <short>*p = new Echo_16Bit<short>(5000);
    					p->processBuffer(a.get16Buffer(), a.getBufferSize());
						}
						a.writeFile();
					}
					//std::cin >> userInput;
					//if(userInput == 'Y'){
						
					//}
					
				}
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
	
	
	loadBuffer b;
	b.readFile("test.wav");
	//b.readFile("wavefiles/yes-8bit-mono.wav");
	
	return 0;
}
