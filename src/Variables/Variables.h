#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../RPN/RPN.h"
#include "../Token/Token.h"

using std::cout;
using std::map;
using std::string;
using std::vector;

struct Variables {
    vector<string> variables;
    map<string, string> variableAndMeaning;

    void replace(string &str, string &old, string &new_);
    void changeVariablesInExpression(string &exp);
    void initVariables();
    void replacementVariables();
    void convertVariablesToNumber();
};
