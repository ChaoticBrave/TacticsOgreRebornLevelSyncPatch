// TacticsOgreRebornSyncPatch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <shobjidl.h> 
#include <string>
#include <winuser.h>
#include <stdio.h>
#include <vector>
#include <list>
#include <stddef.h>
#include <commdlg.h>
#include <commctrl.h>

#include "AddGame.h"


int main()
{
    AddGame checker = AddGame();
    checker.validate();
    if (checker.getIsTOR()) {
        vector<int> num_list = { 176, 0, 235, 35 };
        streampos stat_loc;
        fstream aGame;
        int to_ass;
        char * ch_val;
        aGame.open(checker.getWhole(), ios::in | ios::out | ios::binary | ios::ate);
        for (int i = 0; i < 4; i++) {
            aGame.seekg(4724000 + i, ios::beg);
            stat_loc = aGame.tellg();
            to_ass = aGame.get();
            ch_val = new char(num_list.at(i));
            aGame.seekp(4724000 + i, ios::beg);
            aGame.write(ch_val, 1);
            delete ch_val;
        }
        cout << "Tactics Ogre Reborn successfully patched." << endl;
        system("pause");
        aGame.close();
    }



}