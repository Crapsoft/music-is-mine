#include "Playlist.h"
#include "MP3tag.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>


Playlist::Playlist()
{
	path = "C:\\Users\\*";
}

vector<string> Playlist::FilesandFolders() 
{
	vector<string> filenames;
	string directoryPath(path);
	LPCSTR fpath = (LPCSTR)directoryPath.c_str();
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = FindFirstFile(fpath, &FindFileData);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
				filenames.push_back(FindFileData.cFileName);
		} while (FindNextFile(hFind, &FindFileData));

		FindClose(hFind);
	}

	//Remove .. and desktop.ini files
	for (int i = 0; i < filenames.size(); i++)
	{
		if (filenames[i].compare("desktop.ini") == 0 || filenames[i].size() < 4)
		{
			filenames.erase(filenames.begin() + i);
			vector<string>(filenames).swap(filenames);
		}
	}
	return filenames;
	
}

void Playlist::mp3search() 
{
	vector<string> filenames = FilesandFolders();
	//Remove not .mp3 files
	string str;
	for (int i = 0; i < filenames.size(); i++)
	{
		int size = filenames[i].size();
		str = filenames[i];
		if (str[size - 1] != '3' || str[size - 2] != 'p' || str[size - 3] != 'm')
		{
			filenames.erase(filenames.begin() + i);
			vector<string>(filenames).swap(filenames);
		}
	}
	//Adding full address 
	string path2 = path.substr(0, path.size() - 1);

	for (int i = 0; i < filenames.size() - 1; i++)
	{
		mp3.push_back(path2 + filenames[i]);
	}
	
}

void Playlist::ls() {
	vector<string> list = FilesandFolders();
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << endl;
	}
}
void Playlist:: pwd() {
	cout << path;

}

Playlist::~Playlist()
{

}
