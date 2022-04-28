#pragma once

#include <iostream>
#include <map>
#include <string>

#include "../RPN/RPN.h"
#include "../Token/Token.h"
#include "../Containers/Vector/Vector.h"

typedef struct Variables {
    Vector variables;
    std::map<std::string, std::string> variableAndMeaning;

    static void replace(std::string &str, std::string &old, std::string &new_);
    void changeVariablesInExpression(std::string &exp);
    void initVariables();
    void replacementVariables();
    void convertVariablesToNumber();
} Variables;
