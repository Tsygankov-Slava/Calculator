#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>


struct File {
    std::string path = "/Users/tv/Desktop/Calc/Calc/src/variables.txt";
    std::map<std::string, std::string> getText();
};
