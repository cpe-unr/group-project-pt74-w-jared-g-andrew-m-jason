#include <iostream>
#include <fstream>
#include <dirent.h>
#include <vector>
#include "loadbuffer.h"

int main(){
	/*int userChoice = 10;
	std::string fileName;
	loadBuffer a;
	std::cout << "Enter a filename:" << std::endl;
	std::cin >> fileName;
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
	//a.writeFile("hello.wav");*/
	
	DIR *dir;
	struct dirent *diread;
	std::vector<std::string> files;
	if((dir = opendir("wavefiles")) != nullptr){
		while ((diread = readdir(dir)) != nullptr){
			files.push_back(diread->d_name);
		}
		closedir(dir);
	}
	for(std::string file : files){
		loadBuffer a;
		a.readFile(file);
		std::cout << file << std::endl;
	}
	
	return 0;
}
