#include "FileManager.h"
#include "MP3tag.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <sstream>

FileManager::FileManager()
{
	path = "C:\\*";
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
	for (size_t i = 0; i < filenames.size(); i++)
	{
		if (filenames[i].compare("desktop.ini") == 0 || filenames[i].compare(".."))
		{
			filenames.erase(filenames.begin() + i);
			vector<string>(filenames).swap(filenames);
		}
	}
	return filenames;

}
//Linux command line:
//ls command
void FileManager::ls() {
	vector<string> list = FilesandFolders();
	for (size_t i = 0; i < list.size(); i++)
	{
		cout << list[i] << endl;
	}
}
//pwd command
void FileManager::pwd() {
	cout << path;

}
//cd *folder* command
void FileManager::cdfolder(string com)
{
	vector<string> files = FilesandFolders();
	bool check = false;
	for (size_t i = 0; i < files.size(); i++)
	{
		if (files[i] == com)
		{
			check = true;
			break;
		}
	}
	if (check)
	{
		string temp = path;
		path.erase(path.size() - 1);
		path += com + "\\*";
	}
	else
	{
		cout << "There is no folder with name " << "'" << com << "'";
	}

}
// cd .. command
void FileManager::cdback() 
{
	path.erase(path.size() - 2);
	int index = path.size() - 1;
	for (size_t i = path.size() - 1; i > 0; i--)
	{

		if (path[i] == '\\')
		{
			index = i;
			break;
		}
	}
	path.erase(path.begin() + index, path.end());
	path += "\\*";
}


FileManager::~FileManager()
{
}
