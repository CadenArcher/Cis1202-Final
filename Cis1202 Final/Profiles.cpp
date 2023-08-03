
#include <windows.h>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#include <iostream>
#include "YoutubeClasses.h"
#include "Profiles.h"
using namespace std;

ProfileOne::ProfileOne(string VideoUrl, string VideoNames,string PeofileOneName, int VideoRating) : Youtube(VideoUrl, VideoNames, VideoRating), ProfileName(PeofileOneName){}


string ProfileOne::ReturnProfileName() {
	return ProfileName;
}

