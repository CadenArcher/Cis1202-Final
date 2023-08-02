#include <windows.h>
#include <shellapi.h>
#include <locale>
#include <codecvt>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Profiles.h"
#include <string>
#include "YoutubeClasses.h"
#include "Profile2.h"
using namespace std;

void DisplayVideoAndRating(Youtube[], int);
void AddVideo(Youtube[], int);
void GetFile(ProfileOne[], ProfileTwo[], int&);
template <typename Users>

int main()
{
    int WhatVideo;
    const int VideoList = 10;
    Youtube List[VideoList];
    WhatProfile List[VideoList];
    int HowManyVideo = 0;
    GetFile(List,HowManyVideo);
    
    DisplayVideoAndRating(List, HowManyVideo);
  
    cout << "What video: ";
    cin >> WhatVideo;
        string command = "start " + List[WhatVideo].DisplayVideoLink();
        system(command.c_str());
    
    
    return 0;
}

void DisplayVideoAndRating(Youtube List[], int HowManyVideos) {
    
    for(int i = 0;i < HowManyVideos;i++){

        cout << List[i].DisplayVideoLink() << " Rating: " << List[i].DisplayRating() << endl;

    }

}



void AddVideo(Youtube List[],int HowManyVideos) {

    fstream Videos("YoutubeVideos.bin", ios::out | ios::app);
    
    Youtube You;
    string Video;
    
    int HowManyRating;
    double Rating;
  
    if (!Videos.is_open()) {
        cout << "this didnt open wtf";
    }

    cout << "What Video do you want to add";
    cin >> Video;
  
   
    cout << "What rating do you give the video out of 10";
    cin >> Rating;

    size_t size = Video.size();
    Videos.write(reinterpret_cast<char*>(&size), sizeof(size));
    Videos.write(Video.c_str(), size);
    Videos.write(reinterpret_cast<char*>(&Rating), sizeof(Rating));

    Videos.close();
    List[HowManyVideos].StoreVideoAndVideoInfo(Video, Rating);

}



void GetFile(ProfileOne User1List[], ProfileTwo User2List[], int& HowManyVideos) {

    string YoutubeLink;
    
    double Rating;
    Youtube UserList[2] = { User1List[100], User2List[100] };

   
        fstream Videos;
    
            Videos.open("User1Videos.bin", ios::in | ios::out | ios::binary);



            if (!Videos.is_open()) {
                cout << "this didnt open wtf";
            }

            size_t size;
            while (Videos.read(reinterpret_cast<char*>(&size), sizeof(size))) {
                YoutubeLink.resize(size);
                Videos.read(&YoutubeLink[0], size);

                Videos.read(reinterpret_cast<char*>(&Rating), sizeof(Rating));

                User1List[HowManyVideos].AccountOne(YoutubeLink, Rating);

                HowManyVideos++;


            }
            Videos.open("User1Videos.bin", ios::in | ios::out | ios::binary);



            Videos.close();

    
}