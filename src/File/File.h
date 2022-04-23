#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::ifstream;
using std::map;
using std::string;

struct File {
    string path = "/Users/tv/Desktop/Calc/Calc/src/variables.txt";
    map<string, string> getText();
};
