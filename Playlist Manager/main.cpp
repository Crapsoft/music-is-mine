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


int main()
{
	vector<string> v = SearchFolder("C:\\Users\\Public\\Music\\*");
	cout<< v.back();
	/*TAGdata file("Eleven Wives.mp3");
	cout << file.getArtist() << ' ' << file.getAlbum() << ' ' << file.getTitle() << endl;*/
	system("pause");
	return 0;
}
