#include "Playlist.h"

Playlist::Playlist()
{
	this->name = "default playlist";
}

Playlist::Playlist(string _name)
{
	this->name = _name;
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

Playlist& Playlist::operator+(const Playlist& rhs)
{
	for (int i = 0; i < rhs.mp3.size(); i++) {
		(*this).mp3.push_back(rhs.mp3[i]);
	}
	return *this;
}

Playlist& Playlist::operator+=(const string rhs)
{
	this->mp3.push_back(rhs);
	return *this;
}

Playlist& Playlist::operator-=(const string rhs)
{
	for (int i = 0; i < this->mp3.size(); i++) {
		if (this->mp3[i] == rhs) {
			this->mp3.erase(this->mp3.begin() + i);
		}
	}

	return *this;
}

Playlist& Playlist::operator-=(const Playlist& rhs)
{
	for (int i = 0; i < rhs.mp3.size(); i++) {
		for (int j = 0; j < this->mp3.size(); j++) {
			if (rhs.mp3[i] == this->mp3[j]) {
				this->mp3.erase(this->mp3.begin() + j);
			}
		}
	}

	return *this;
}

int Playlist::outputt()
{
	ofstream myfile;
	myfile.open("playlist.m3u");
	myfile << "#EXTM3U" << endl;
	for (int i = 0; i < this->mp3.size(); i++) {
		myfile << "#EXTINF:";
		const char * sttr = this->mp3[i].c_str();
		TAGdata song(sttr);
		myfile << this->mp3[i] << endl;
	}
	myfile.close();
	return 1;
}