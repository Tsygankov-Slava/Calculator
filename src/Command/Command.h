#pragma once

#include <iostream>
#include <string>

#include "../Containers/Vector/Vector.h"
#include "../File/File.h"
#include "../Variables/Variables.h"
#include "../History/History.h"

struct Command : Variables {
    bool isCommand(std::string &str, Variables &var, File &file, History &history);
    void outVariables(std::map<std::string, std::string> &variableAndMeaning, std::string var);
    void delVariables(Variables &var, std::string &v, File &file);
    void deleteVarInFile(File file, std::string var);
    Vector getVariables(std::string &str);
};
