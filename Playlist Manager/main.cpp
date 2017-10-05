#include "MP3tag.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
vector<string> SearchFolder(string path) 
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
	return filenames;
}
vector<string> MP3Path(string path) 
{
	vector<string> files = SearchFolder("C:\\Users\\Public\\Music\\*");
	string str;
	//Remove ... and desktop.ini files
	for (int i = 0; i < files.size(); i++)
	{
		if (files[i].compare("desktop.ini") == 0 || files[i].size()<3)
		{
			files.erase(files.begin() + i);
			vector<string>(files).swap(files);
		}
	}
	//Remove not .mp3 files
	for (int i = 0; i < files.size(); i++)
	{
		
		int size = files[i].size();
		str = files[i];
		
		if (str[size - 1] != '3'|| str[size - 2] !='p' || str[size - 3] != 'm')
		{
			files.erase(files.begin() + i);
			vector<string>(files).swap(files);
		}
	}
	return files;
}


int main()
{
	/*vector<string> v = SearchFolder("C:\\Users\\Public\\Music\\*");
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}*/
	
	vector<string> v = MP3Path("s");
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	/*TAGdata file("C:\\Users\\Public\\Music\\fd68d237712c49.mp3");
	cout << file.getArtist() << ' ' << file.getAlbum() << ' ' << file.getTitle() << endl;*/
	system("pause");
	return 0;
}
