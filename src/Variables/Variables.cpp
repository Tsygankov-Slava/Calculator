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
    for (auto &i : variables) {
        replace(exp, i, variableAndMeaning[i]);
    }
}

void Variables::initVariables() {
    for (auto &i : variableAndMeaning) {
        variables.push_back(i.first);// Записываем все переменные в массив
    }
}

void Variables::replacementVariables() {
    for (int n = 0; n < variables.size(); ++n) {
        for (auto &i : variableAndMeaning) {
            for (auto j : variables) {
                replace(variableAndMeaning[i.first], j, variableAndMeaning[j]);
            }
        }
    }
}


void Variables::convertVariablesToNumber() {
    RPN rpn;
    for (auto &i : variableAndMeaning) {
        std::string exp = i.second;
        auto g = rpn.toPostfix(exp);
        if (!g.empty()) {
            auto p = RPN::calcRPN(g);
            std::string str = RPN::convertComplex2String(p.top());
            variableAndMeaning[i.first] = str;
        }
    }
}