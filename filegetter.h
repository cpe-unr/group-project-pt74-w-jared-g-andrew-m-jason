#ifndef FILEGETTER_H
#define FILEGETTER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>

class fileGetter{
private:
	DIR *dir;
	struct dirent *diread;
	std::vector<std::string> files;
public:
	std::vector<std::string> getFiles(std::string directory);
};

#endif
