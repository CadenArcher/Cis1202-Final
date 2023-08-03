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

void DisplayVideoAndRating(ProfileOne User1List[], ProfileTwo User2List[], int HowManyUser1Videos, int HowManyUser2Videos, int WhatUser);
void AddVideo(ProfileOne User1List[], ProfileTwo User2List[], int& HowManyUser1Videos, int& HowManyUser2Videos, int WhatProfile);
void LaunchUrl(ProfileOne User1List[], ProfileTwo User2List[], int HowManyUser1Videos, int HowManyUser2Videos,int, int WhatUser);
void GetFile(ProfileOne User1List[], ProfileTwo User2List[], int& HowManyUser1Videos, int& HowManyUser2Videos);


int main(){

    const int VideoList = 20;
    ProfileOne User1List[VideoList];
    ProfileTwo User2List[VideoList];
    int PlayVideoOrNot;

    int HowManyUser1Video = 0;
    int HowManyUser2Video = 0;

    int WhatProfile = 3;
    bool KeepPLayingVideos = true;
    
    GetFile(User1List, User2List, HowManyUser1Video, HowManyUser2Video);
   
        do {
            KeepPLayingVideos = true;
            cout << "Welcome to my Youtube Storage and Player\n"
                << "To start please pick a profile, 1 or 2. Both are allowed to store up to 20 videos\n"
                << "After that the screen will display each video name and a rating\n"
                << "type what video you want to play and it will pop up in your default brower\n"
                << "Add a video first if this is the first time running the program";

            cout << "\n\nPlease choose what Profile\n"
                << User1List[0].ReturnProfileName() << endl
                << User2List[0].ReturnProfileName() << endl
                << "What Profile do you choose, One or Two";
            cin >> WhatProfile;
            if (WhatProfile > 2) {
                cout << "Sorry, please choose a number between 1 and 2";
            }
            
        } while (WhatProfile > 2);
        while (KeepPLayingVideos == true) {
            
     
           
            cout << "\nWhat Video do you want to laucnh or you can exit the program by typing 21, or go back the main menu to swtich profiles by typing 22";
            cin >> PlayVideoOrNot;

            if (PlayVideoOrNot <= 20) {

                LaunchUrl(User1List, User2List, HowManyUser1Video, HowManyUser2Video, PlayVideoOrNot, WhatProfile);

            }
            else if (PlayVideoOrNot == 21) {
                break;
            }
            else if (PlayVideoOrNot == 22) {
                KeepPLayingVideos = false;
            }

        } 

    
    
    return 0;
}

void DisplayVideoAndRating(ProfileOne User1List[], ProfileTwo User2List[], int HowManyUser1Videos, int HowManyUser2Videos, int WhatUser) {
    
    if (WhatUser == 1) {
        cout << User1List[0].ReturnProfileName();
        for (int i = 0;i < HowManyUser1Videos;i++) {
           
                cout << "Video " << i << ": " << User1List[i].ReturnVideoName() << " Rating: " << User2List[i].ReturnVideoRating() << endl;
            
        }
    }
    else if (WhatUser == 2) {
        cout << User2List[0].ReturnProfileName();
        for (int i = 0;i < HowManyUser2Videos;i++) {
            if (i < 10) {
                cout << "Video " << i << ": " << User2List[i].ReturnVideoName() << " Rating: " << User2List[i].ReturnVideoRating() << endl;
            }
        }
    }
}

void LaunchUrl(ProfileOne User1List[], ProfileTwo User2List[], int HowManyUser1Videos, int HowManyUser2Videos, int WhatVideo, int WhatUser) {
  
    if (WhatUser == 1) {
        if (WhatVideo <= HowManyUser1Videos) {
            cout << User1List[WhatVideo].ReturnVideoUrl();
            string command = "start " + User1List[WhatVideo].ReturnVideoUrl();
            system(command.c_str());
        }
    }
    else if (WhatUser == 2) {
        if (WhatVideo < HowManyUser2Videos) {
            string command = "start " + User2List[WhatVideo].ReturnVideoUrl();
            system(command.c_str());
        }
    }
}


void AddVideo(ProfileOne User1List[], ProfileTwo User2List[], int& HowManyUser1Videos, int& HowManyUser2Videos, int WhatProfile) {

    fstream Videos("User1Videos.bin", ios::out | ios::app);
    
  
    string VideoName;
    string Video;
    string ProfileName = "test";
    string ProfileNamePlaceHolder;
    int HowManyRating;
    double Rating;
  
    if (!Videos.is_open()) {
        cout << "this didnt open wtf";
    }
    cout << "Whats the name of the video";
    cin >> VideoName;
    cin.ignore();
    cout << "What VideoUrl do you want to add";
    cin >> Video;
    cin.ignore();
   
    cout << "What rating do you give the video out of 10";
    cin >> Rating;

  


    size_t VideoNameSize = VideoName.size();
    size_t VideoSize = Video.size();
    size_t NameSize = ProfileName.size();

    Videos.write(reinterpret_cast<char*>(&VideoNameSize), sizeof(VideoNameSize));
    Videos.write(VideoName.c_str(), VideoNameSize);

    Videos.write(reinterpret_cast<char*>(&VideoSize), sizeof(VideoSize));
    Videos.write(Video.c_str(), VideoSize);

    Videos.write(reinterpret_cast<char*>(&NameSize), sizeof(NameSize));
    Videos.write(ProfileName.c_str(), NameSize); 

    Videos.write(reinterpret_cast<char*>(&Rating), sizeof(Rating));
    Videos.close();
    if (WhatProfile == 1) {
        ProfileOne UserOne(Video, VideoName, ProfileNamePlaceHolder, Rating);
        User1List[HowManyUser1Videos + 1] = UserOne;
    }
    else if (WhatProfile == 2) {
        ProfileTwo UserTwo(Video, VideoName, ProfileNamePlaceHolder, Rating);
        User2List[HowManyUser2Videos + 1] = UserTwo;
    }
}



void GetFile(ProfileOne User1List[], ProfileTwo User2List[], int& HowManyUser1Videos, int& HowManyUser2Videos) {
    double Rating;
    string YoutubeLink;
    string VideoName;
    string ProfileName = "test";
    int UserName = 0;

        fstream Videos;
    
            Videos.open("User1Videos.bin", ios::in | ios::out | ios::binary);

            if (!Videos.is_open()) {
                cout << "this didnt open wtf";
            }
            size_t size;
            while (Videos.read(reinterpret_cast<char*>(&size), sizeof(size))) {
                VideoName.resize(size);
                Videos.read(&VideoName[0], size);

                Videos.read(reinterpret_cast<char*>(&size), sizeof(size));
                YoutubeLink.resize(size);
                Videos.read(&YoutubeLink[0], size);

                Videos.read(reinterpret_cast<char*>(&size), sizeof(size));
                ProfileName.resize(size);
                Videos.read(&ProfileName[0], size);

                Videos.read(reinterpret_cast<char*>(&Rating), sizeof(Rating));

                ProfileOne newUser(YoutubeLink, VideoName, ProfileName, Rating);
                User1List[HowManyUser1Videos] = newUser;
                HowManyUser1Videos++;
            }

            Videos.close();
            UserName = 0;
            Videos.open("User2Videos.bin", ios::in | ios::out | ios::binary); 

            
            while (Videos.read(reinterpret_cast<char*>(&size), sizeof(size))) {
                VideoName.resize(size);
                Videos.read(&VideoName[0], size);

                Videos.read(reinterpret_cast<char*>(&size), sizeof(size));
                YoutubeLink.resize(size);
                Videos.read(&YoutubeLink[0], size);

                Videos.read(reinterpret_cast<char*>(&size), sizeof(size));
                ProfileName.resize(size);
                Videos.read(&ProfileName[0], size);

                Videos.read(reinterpret_cast<char*>(&Rating), sizeof(Rating));

                ProfileTwo newUser(YoutubeLink, VideoName, ProfileName, Rating);
                User2List[HowManyUser1Videos] = newUser;
                HowManyUser1Videos++;
            }

            Videos.close();

    
}