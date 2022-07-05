#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "playerFile.h"
#include <fstream>
#include <string>

class Sign_inFile {

public:
	int checkFile(string name,string password);

	void updateFile();

	map<string, string> m_playerData;

	int m_size;
};