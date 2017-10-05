#include "MP3tag.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
	TAGdata file("Eleven Wives.mp3");
	cout << file.getArtist() << ' ' << file.getAlbum() << ' ' << file.getTitle() << endl;


	


	system("pause");
	return 0;
}
