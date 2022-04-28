#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../RPN/RPN.h"
#include "../Token/Token.h"

typedef struct Variables {
    std::vector<std::string> variables;
    std::map<std::string, std::string> variableAndMeaning;

    static void replace(std::string &str, std::string &old, std::string &new_);
    void changeVariablesInExpression(std::string &exp);
    void initVariables();
    void replacementVariables();
    void convertVariablesToNumber();
} Variables;
