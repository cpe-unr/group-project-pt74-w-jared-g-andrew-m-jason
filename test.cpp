#include <iostream>
#include <fstream>
#include "waveheader.h"
#include <vector>
#include "loadbuffer.h"
#include "filegetter.h"

int main(){
	int userChoice = 10;
	std::string directoryName;
	std::cout << "Enter a directory:" << std::endl;
	std::cin >> directoryName;
	/*while(userChoice != 0){
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
	//a.writeFile("hello.wav");*/
	std::string fileName;
	fileGetter a;
	std::vector<std::string> files = a.getFiles(directoryName);
	for(std::string file : files){
		loadBuffer a;
		a.readFile(file);
		std::cout << "Enter a name for copy: ";
		std::cin >> fileName;
		a.writeFile(fileName);
	}
	//loadBuffer a;
	//a.readFile("wavefiles/yes-8bit-mono.wav");
	return 0;
}
