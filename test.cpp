/** @file */
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
						/** 
						//tried to implement my processors but wasnt able to get them to work well with templates :(
						//below is how it should work conceptaily using Echo as an exampel 
						//It covers how to handle it with stero. lord have mercy
						
						if(a.getBitDepth() == 16){  //check if 16 or 8 bit
							if(a.getNumChannels() == 2){ //check if stero or mono
								for(int i = 1; i < bufferSize; i = i + 2) { //split buffer into 2 chanels 
									RightBuffer[i] = buffer[i];
								}
								processor <short>*p = new Echo_16Bit<short>(5000);  //Process each channel 
    								p->processBuffer(RightBuffer, a.getBufferSize());
								
								for(int i = 2; i < bufferSize; i = i + 2) {  
									LeftBuffer[i] = buffer[i];
								}
								processor <short>*p = new Echo_16Bit<short>(5000);
    								p->processBuffer(LeftBuffer, a.getBufferSize());
    								
    								for(int i = 1; i < bufferSize; i = i + 2){  //Stich them back into one buffer now
    									buffer[i] = RightBuffer[i];
    								}
    								
    								for(int i = 2; i < bufferSize; i = i + 2){
    									buffer[i] = LeftBuffer[i];
    								}
    								*/
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
				//Same process as Normalization
				break;
			case 3:
				std::cout << "Applying Echo\n" << std::endl;
				//Same process as Normalization
				break;
			case 0:
				std::cout << "Exiting Program" << std::endl;
				break;
			default:
				std::cout << "Please enter a valid number\n" << std::endl;
		}
		
	}
<<<<<<< HEAD
	
	
=======
	fileGetter a;
	std::vector<std::string> files = a.getFiles(directoryName);
	for(std::string file : files){
		std::cout << "Would you like to modify the metadata? Y/N: ";
		char userInput;
		std::cin >> userInput;
		if(userInput == 'Y'){
			loadBuffer().writeCSV(files)
		}
		loadBuffer a;
		a.readFile(file);
		a.writeFile();
	}
>>>>>>> 1243ef9d604c867e985737ede324db424c5ba2ec
	loadBuffer b;
	b.readFile("test.wav");
	//b.readFile("wavefiles/yes-8bit-mono.wav");
	
	return 0;
}
