
#include <windows.h>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#include <iostream>
#include "YoutubeClasses.h"
#include "Profiles.h"
using namespace std;

ProfileOne::ProfileOne(string VideoUrl, string VideoNames, int VideoRating) : Youtube(VideoUrl, VideoNames, VideoRating){}

