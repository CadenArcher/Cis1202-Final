#pragma once

#include <windows.h>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#include <iostream>
#include "YoutubeClasses.h"
using namespace std;

class ProfileOne:public Youtube {
	
private:

	string ProfileName;


public:
	
	ProfileOne(string, string, int);
	

};