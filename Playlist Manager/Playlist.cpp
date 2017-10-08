#include "Playlist.h"
#include "MP3tag.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>


Playlist::Playlist()
{
	
}



//void Playlist::mp3search() 
//{
//	vector<string> filenames = FilesandFolders();
//	//Remove not .mp3 files
//	string str;
//	for (int i = 0; i < filenames.size(); i++)
//	{
//		int size = filenames[i].size();
//		str = filenames[i];
//		if (str[size - 1] != '3' || str[size - 2] != 'p' || str[size - 3] != 'm')
//		{
//			filenames.erase(filenames.begin() + i);
//			vector<string>(filenames).swap(filenames);
//		}
//	}
//	//Adding full address 
//	string path2 = path.substr(0, path.size() - 1);
//
//	for (int i = 0; i < filenames.size() - 1; i++)
//	{
//		mp3.push_back(path2 + filenames[i]);
//	}
//	
//}



Playlist::~Playlist()
{

}
