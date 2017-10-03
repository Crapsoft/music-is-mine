#include "MP3tag.h"
#include <iostream>
#include <fstream>
#include <string>

const int fileNameLength = 1024;
const int mp3TagSize = 128;

using namespace std;

int main()
{
	TAGdata tagStruct;
	char  fileName[fileNameLength + 1];
	ifstream mp3File;
	char buffer[mp3TagSize + 1];

	cout << "MP3 File Name? ";
	cin.getline(fileName, fileNameLength);

	mp3File.open(fileName);
	buffer[mp3TagSize] = '\0';  //just a precaution

	if (mp3File) {
		cout << "Successful open of " << fileName << endl;
	}
	else {
		cerr << "***Aborting*** Could not open " << fileName << endl;
		return 1;
	}

	//move file pointer to 128 bytes off the end of the file.
	mp3File.seekg(-(mp3TagSize), ios::end);
	if (mp3File.fail()) {
		cerr << "Could not seek, Aborting " << endl;
		return 1;
	}

	//get the data
	mp3File.read(reinterpret_cast <char *>(&tagStruct), mp3TagSize);
	if (mp3File.fail()) {
		cerr << "Could not read after seeking, Aborting " << endl;
		return 1;
	}

	mp3File.close();

	system("pause");
	return 0;
}
