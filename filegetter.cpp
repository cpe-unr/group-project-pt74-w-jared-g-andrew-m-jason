#include "filegetter.h"

std::vector<std::string> fileGetter::getFiles(std::string directory){
	const char* direct = directory.c_str();
	if((dir = opendir(direct)) != nullptr){
		while ((diread = readdir(dir)) != nullptr){
			std::string path = directory + std::string("/") + diread->d_name;
			files.push_back(path);
		}
		closedir(dir);
		return files;
	}
	else{
		std::cout << "Could not open directory" << std::endl;
		return files;
	}
}
