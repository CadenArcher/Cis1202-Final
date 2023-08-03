#pragma once

#include <windows.h>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#include <iostream>
#include "YoutubeClasses.h"

class ProfileTwo :public Youtube {

private:


	string ProfileName;

public:
	ProfileTwo() = default;
	ProfileTwo(string, string, string, int);
	string ReturnProfileName();


};