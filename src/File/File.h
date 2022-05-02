#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>


struct File {
    std::string path = " ";

    std::map<std::string, std::string> getText();
};
