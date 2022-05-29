#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "../Variables/Variables.h"

struct File {
    std::string pathVariables = " ";
    std::string pathHistory = " ";
    std::map<std::string, std::string> getText();

    void checkFileVariablesAccess(Variables &var);
    bool checkFileHistoryAccess();
    void addVariable(std::string &str);
};
