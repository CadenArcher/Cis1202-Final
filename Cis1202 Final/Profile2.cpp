#include <windows.h>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#include <iostream>
#include "YoutubeClasses.h"
#include "Profile2.h"

ProfileTwo::ProfileTwo(string VideoUrl, string VideoNames,string ProfileTwoName, int VideoRating) : Youtube(VideoUrl, VideoNames, VideoRating), ProfileName(ProfileTwoName) {}

string ProfileTwo::ReturnProfileName() {
	return ProfileName;
}
