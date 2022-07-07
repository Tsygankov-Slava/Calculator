#include "Variables.h"

void Variables::initVariables() {
    for (auto &i : variableAndMeaning) {
        variables.push_back(i.first);// Записываем все переменные в массив
    }
}

bool Variables::isVariable(std::string &token) {
    for (int i = 0; i < variables.index; ++i) {
        if (token == variables.arrString[i]) {
            return true;
        }
    }
    return false;
}

void Variables::ReplacementVariables() {
    for (int n = 0; n < variables.index; ++n) {
        for (int i = 0; i < variables.index; ++i) {
            int index = 0, sizeExp = variableAndMeaning[variables.arrString[i]].size();
            std::string token;
            while (index < sizeExp) {
                int oldIndex = index;
                token = Token::readToken(variableAndMeaning[variables.arrString[i]], index);
                if (isVariable(token)) {
                    variableAndMeaning[variables.arrString[i]].replace(oldIndex, index - oldIndex, "(" + variableAndMeaning[token] + ")");
                }
            }
        }
    }
}

void Variables::changeVariablesInExpression(std::string &exp) {
    int index = 0, sizeExp = exp.size();
    std::string token;
    std::set<std::string> operationsAndFunctions = {"+", "-", "*", "/", "^", "_", "phase", "mag", "sin", "cos", "log", "sqrt", "exp", "real", "imag", "(", ")", "E", "PI"};
    while (index < sizeExp) {
        int oldIndex = index;
        token = Token::readToken(exp, index);
        if (isVariable(token)) {
            exp.replace(oldIndex, index - oldIndex, "(" + variableAndMeaning[token] + ")");
            sizeExp = exp.size();
            index = 0;
            continue;
        } else {
            if (std::all_of(token.begin(), token.end(), [](const char& ch) { return isdigit(ch); })) {
                continue;
            }

            bool flag = false;
            for (auto &oAf : operationsAndFunctions) {
                if (token == oAf) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
        }
        throw std::invalid_argument( "Error: Неизвестная переменная -> " + token);
    }
}

bool Variables::variableDefinition(std::string &str) {
    if (str.find('=') != std::string::npos) {
        return true;
    }
    return false;
}
