#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <random>

using namespace std;
using std::filesystem::current_path;
using std::filesystem::path;
using std::filesystem::u8path;

class AddGame
{
private:
	path cp;
	bool isTOR;


public:
	AddGame();
	void validate();
	path getWhole();
	path getPath();
	string getStringPath();
	bool getIsTOR();
};