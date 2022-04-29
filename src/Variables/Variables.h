#pragma once

#include <iostream>
#include <map>
#include <string>

#include "../Containers/Vector/Vector.h"
#include "../RPN/RPN.h"
#include "../Token/Token.h"

typedef struct Variables {
    Vector variables;
    std::map<std::string, std::string> variableAndMeaning;

    void initVariables();
    void ReplacementVariables();
    bool isVariable(std::string &token);
    void changeVariablesInExpression(std::string &exp);
} Variables;
