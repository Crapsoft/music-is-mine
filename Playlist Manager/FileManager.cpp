#include "FileManager.h"
#include "MP3tag.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>


FileManager::FileManager()
{
	path = "C:\\Users\\*";
}
string FileManager::getPath() {
	return path;
}
vector<string> FileManager::FilesandFolders()
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
void FileManager::ls() {
	vector<string> list = FilesandFolders();
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << endl;
	}
}
void FileManager::pwd() {
	cout << path;

}


FileManager::~FileManager()
{
}
