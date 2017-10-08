#pragma once
#include <vector>
#include <string>
using namespace std;
class Playlist
{
private:
	vector<string> mp3;
	string path;
public:
	Playlist();
	vector<string> FilesandFolders();
	void mp3search();
	void ls();
	void pwd();
	~Playlist();
};

