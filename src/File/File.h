#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>


struct File {
    std::string path = "../src/File/variables.txt";
    std::map<std::string, std::string> getText();
};
