#include <windows.h>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#include <iostream>
using namespace std;

int main()
{
    string Video;
    cin >> Video;
    string command = "start " + Video;
    system(command.c_str());
    cout << Video;
    
    return 0;
}

