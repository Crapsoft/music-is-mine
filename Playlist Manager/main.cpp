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
	string path = "C:\\Users\\Public\\Music";
	TAGdata file("C:\\Users\\Public\\Music\\fd68d237712c49.mp3");
	//cout << file.getArtist() << ' ' << file.getAlbum() << ' ' << file.getTitle() << endl;
	string cmd = "";
	do
	{
		cout << path << " ";
		getline(cin, cmd);
		if (cmd.find("ls") == 0)
		{
			ls();
		}
		else if (cmd.find("cd") == 0)
		{
			if (cmd.find("..") == 3)
			{
				if (path.length() <= 4)
				{
					cout << "Commands can nott be performed" << endl;
				}
				else
				{
					path.erase((path.substr(0, path.length() - 2)).rfind("\\") + 1);
				}
			}
			else if (cmd.find("\\") == cmd.length() - 2)
			{
				path += cmd.substr(3, cmd.length() - 2);
			}
			else if (cmd.find(":\\") == 4)
			{
				path = cmd.substr(3);
			}
			else
			{
				cout << "Incorrect form!" << endl;
			}
		}
		else if (cmd.find("create") == 0)
		{
			if (cmd.find("create_null") == 0)
			{
				//create
			}
			else
			{
				//Playlist A(path, cmd.substr(7));
				//A.getSongs();
			}
		}
		else if (cmd.find("add") == 0)
		{
			if (cmd.find("_file") == 4)
			{
				//B += cmd.substr(11);
				//add
			}
			else if (cmd.find("_playlist") == 4)
			{
				//B += C;
			}
			else
			{
				//B + path;
			}
		}
		else if (cmd.find("delete") == 0)
		{

			if (cmd.find("_file") == 5)
			{
				//B -= cmd.substr(11);
				//vidnyaty
			}
			else if (cmd.find("_playlist") == 5)
			{
				//B -= C;
			}
			else
			{
				//B - path;
			}
		}
		else if (cmd.find("exit") == 0)
		{
		}
		else if (cmd.find("help") == 0)
		{
			cout << "ls" << endl;
			cout << "cd .." << endl;
			cout << "cd subfolder\\" << endl;
			cout << "cd adress\\" << endl;
			cout << "create <Name.m3u>" << endl;
			cout << "create_null <Name.m3u>" << endl;
			cout << "add_file <adress.mp3>" << endl;
			cout << "add_folder" << endl;
			cout << "add_playlist" << endl;
			cout << "delete_file <adress.mp3>" << endl;
			cout << "delete_folder" << endl;
			cout << "delete_playlist" << endl;
		}
		else
		{
			cout << "ERROR_404: such command not found. Please, try again, or enter <help> to read commands" << endl;
			
		}
	} 
	while (cmd != "exit");
	system("pause");
	return 0;
}
