#include <windows.h>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#include <iostream>
#include "YoutubeClasses.h"
#include "Profile2.h"

ProfileTwo::ProfileTwo(string VideoUrl, string VideoNames, int VideoRating) : Youtube(VideoUrl, VideoNames, VideoRating) {}