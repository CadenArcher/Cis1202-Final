#pragma once

#include <windows.h>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#include <iostream>
#include "YoutubeClasses.h"

class ProfileTwo :public Youtube {

private:


	string UserName;

public:
	
	ProfileTwo(string,string, int);
	string ProfileName;


};