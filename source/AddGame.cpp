#pragma warning(disable:4996)

#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>

#include "AddGame.h"

using namespace std;
struct stat sb;


AddGame::AddGame() {
    cp = current_path();
    isTOR = false;
}

path AddGame::getPath() {
    return cp;
}

path AddGame::getWhole() {
    if (std::filesystem::exists(getStringPath() + "\\Tactics Ogre Reborn.exe")) {
        return getStringPath() + "\\Tactics Ogre Reborn.exe";
    }
    else {
        cout << "File not found. You must have Tactics Ogre Reborn.exe in your directory." << endl;
        return "";
    }
}

string AddGame::getStringPath() {
    return cp.string();
}

bool AddGame::getIsTOR() {
    return isTOR;
}

void AddGame::validate() {
    if (getWhole() == "") {
        cout << "Invalid file." << endl;
        system("pause");
    }
    else {
        string gam_com;
        streampos address;
        fstream aGame;
        int add_val;
        gam_com = "";
        aGame.open(getWhole(), ios::in | ios::out | ios::binary | ios::ate);
        if (!aGame) {
            cout << "File not found." << endl;
            aGame.close();
            system("pause");
        }
        else if (filesystem::file_size(getWhole()) != 14183184) {
            cout << "Please unpack this file using Steamless." << endl;
            aGame.close();
            system("pause");
        }
        else {
            for (int o = 12347880; o < 12347899; o++) {
                aGame.seekg(o, ios::beg);
                address = aGame.tellg();
                add_val = aGame.get();
                gam_com += to_string(add_val);
            }
            if (gam_com == "84979911610599115327910311410158328210198111114") {
                isTOR = true;
                cout << "File accepted!" << endl;
            }
            else {
                cout << "This isn't Tactics Ogre: Reborn!" << endl;
                aGame.close();
                system("pause");
            }
        }
    }
}
