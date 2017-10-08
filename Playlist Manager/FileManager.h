#pragma once
#include <string>
#include <vector>
using namespace std;
class FileManager
{
private:
	string path;
public:
	FileManager();
	string getPath();
	vector<string> FilesandFolders();
	void ls();
	void pwd();

	~FileManager();
};

