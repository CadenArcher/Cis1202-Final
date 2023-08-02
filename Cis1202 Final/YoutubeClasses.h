#pragma once
#include <windows.h>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#include <iostream>
using namespace std;

class Youtube {
private:
	
	string VideoName;
	string YoutubeLink;
	int Rating;

public:

	Youtube(string, string, int);
	int ReturnVideoRating();
	string ReturnVideoName();
	string ReturnVideoUrl();
	void VideoAndVideoInfo();
};