#pragma once

#include "MP3tag.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class Playlist
{
private:
	vector<string> mp3;
	string name;
	
public:
	Playlist();
	Playlist(string name);
	void mp3search();
	~Playlist();
	Playlist& operator+(const Playlist& rhs);
	Playlist& operator+=(const string rhs);
	Playlist& operator-=(const string rhs);
	Playlist& operator-=(const Playlist& rhs);
	int outputt();
};

