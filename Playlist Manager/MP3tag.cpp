#include "MP3tag.h"
#include <fstream>
#include <iostream>
#include <exception>

using namespace std;

TAGdata::TAGdata(char* path)
{
	const int fileNameLength = 1024;
	const int mp3TagSize = 128;

	ifstream mp3File;
	char buffer[mp3TagSize + 1];

	mp3File.open(path);
	buffer[mp3TagSize] = '\0';  //just a precaution

	if (mp3File) {
		cout << "Successful open of " << path << endl;
	}
	else {
		cerr << "***Aborting*** Could not open " << path << endl;
		throw invalid_argument("Invalid argument \n");
	}

	//move file pointer to 128 bytes off the end of the file.
	mp3File.seekg(-(mp3TagSize), ios::end);
	if (mp3File.fail()) {
		cerr << "Could not seek, Aborting " << endl;
		throw invalid_argument("Invalid argument \n");
	}

	//get the data
	mp3File.read(reinterpret_cast <char *>(this), mp3TagSize);
	if (mp3File.fail()) {
		cerr << "Could not read after seeking, Aborting " << endl;
		throw invalid_argument("Invalid argument \n");;
	}

	mp3File.close();
}