#pragma once

#include <string>
#include <fstream>
#include <iostream>

struct History {

    void inHistory(std::string &path, std::string text);
    void outHistory(std::string &path);
    void clearHistory(std::string &path);
};
