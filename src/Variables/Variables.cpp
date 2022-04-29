#include "Variables.h"

void Variables::replace(std::string &str, std::string &old, std::string &new_) {
    int pos = str.find(old);
    while (pos != -1) {
        str.replace(pos, old.size(), new_);
        pos = str.find(old);
    }
    str = "(" + str + ")";
}

void Variables::changeVariablesInExpression(std::string &exp) {
    for (int i = 0; i < variables.index; ++i) {
        replace(exp, variables.arrString[i], variableAndMeaning[variables.arrString[i]]);
    }
}

void Variables::initVariables() {
    for (auto &i : variableAndMeaning) {
        variables.push_back(i.first);// Записываем все переменные в массив
    }
}

void Variables::replacementVariables() {
    for (int n = 0; n < variables.index; ++n) {
        for (auto &i : variableAndMeaning) {
            for (int j = 0; j < variables.index; ++j) {
                replace(variableAndMeaning[i.first], variables.arrString[j], variableAndMeaning[variables.arrString[j]]);
            }
        }
    }
}


void Variables::convertVariablesToNumber() {
    RPN rpn;
    for (auto &i : variableAndMeaning) {
        std::string exp = i.second;
        auto g = rpn.toPostfix(exp);
        if (!g.index) {
            auto p = RPN::calcRPN(g);
            std::string str = RPN::convertComplex2String(p.top());
            variableAndMeaning[i.first] = str;
        }
    }
}