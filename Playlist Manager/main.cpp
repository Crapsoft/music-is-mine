#include "MP3tag.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Playlist.h"

using namespace std;

void ls();
void pwd();
void cdfolder(string com);
void cdback();

//C:\\Users\\Public\\Music\\*    for personal use
int main()
{

	TAGdata file("C:\\Users\\Public\\Music\\fd68d237712c49.mp3");
	//cout << file.getArtist() << ' ' << file.getAlbum() << ' ' << file.getTitle() << endl;
	string operation = "";
	do
	{
		getline(cin, operation);
		if (operation.find("ls") == 0)
		{
			ls();
		}
	} 
	while (operation != "exit");
	system("pause");
	return 0;
}
