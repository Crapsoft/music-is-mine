#include "MP3tag.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
vector<string> MP3path(string path) 
{
	//Searching for all files in a folder:
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
	
	//toString

	string str;
	//Remove .. and desktop.ini files
	for (int i = 0; i < filenames.size(); i++)
	{
		if (filenames[i].compare("desktop.ini") == 0 || filenames[i].size()<4)
		{
			filenames.erase(filenames.begin() + i);
			vector<string>(filenames).swap(filenames);
		}
	}
	//Remove not .mp3 files
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
	vector<string> v;
	for (int i = 0; i < filenames.size()-1; i++)
	{
		v.push_back(path2 + filenames[i]);
	}
	return v;
}
//C:\\Users\\Public\\Music\\*    for personal use




int main()
{
	vector<string> v = MP3path("C:\\Users\\Public\\Music\\*");
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	
	/*TAGdata file("C:\\Users\\Public\\Music\\fd68d237712c49.mp3");
	cout << file.getArtist() << ' ' << file.getAlbum() << ' ' << file.getTitle() << endl;*/
	system("pause");
	return 0;
}
