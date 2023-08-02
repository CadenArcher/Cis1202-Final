
#include <windows.h>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "YoutubeClasses.h"
using namespace std;

Youtube::Youtube(string YouTubeUrl,string VideoNames, int VideoRating) : YoutubeLink(YouTubeUrl), Rating(VideoRating),VideoName(VideoNames) {}


int Youtube::ReturnVideoRating() {
	return Rating;
}
string Youtube::ReturnVideoUrl() {
	return YoutubeLink;
}
string Youtube::ReturnVideoName() {
	return VideoName;
}
void Youtube::VideoAndVideoInfo() {
	cout << "Video Name: " << ReturnVideoName()
		<< "\nVideo Rating: " << ReturnVideoRating();
}


