#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "filegetter.h"
#include "csvWriter.h"

using namespace std;

bool csvWriter::writeMetadataToFile(string fileInput, string artist, string songName){
	ofstream fileOutput ("metadata.txt");
	fileOutput << songName << "," << artist << "," << endl;
	fileOutput.close();
	return true;
}

