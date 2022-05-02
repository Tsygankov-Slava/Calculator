#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "../Variables/Variables.h"

struct File {
    std::string path = " ";

    std::map<std::string, std::string> getText();
    void checkFileAccess(Variables &var);
};
