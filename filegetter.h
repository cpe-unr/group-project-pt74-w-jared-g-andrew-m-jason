#ifndef FILEGETTER_H
#define FILEGETTER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
/**
* This is the fileGetter class.
*/
class fileGetter{
private:
	DIR *dir;
	struct dirent *diread;
	std::vector<std::string> files;
public:
	/**
	* Gets files from a string directory
	* @param directory - string 
	*/
	std::vector<std::string> getFiles(std::string directory);
};

#endif
