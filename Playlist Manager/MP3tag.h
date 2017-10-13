#pragma once

#ifndef __MP3tag_h
#define __MP3tag_h

class TAGdata
{
public:
	char tag[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[30];
	int genre;
	
	TAGdata(const char* path);
	char* getTitle();
	char* getArtist();
	char* getAlbum();
	char* getYear();
	int getGenre();
};

#endif
