#include "Variables.h"

void Variables::replace(string &str, string &old, string &new_) {
    cout << "\nREPLACE\n";
    cout << "ПРИШЛО: " << str << " -> " << old << " -> " << new_ << "\n";
    int pos = str.find(old);
    while (pos != -1) {
        cout << "pos -> " << pos << "\n";
        str.replace(pos, old.size(), new_);
        cout << "ПОСЛЕ ЗАМЕНЫ -> " << str << "\n";
        pos = str.find(old);
    }
    cout << "----------\n";
}

void Variables::changeVariablesInExpression(string &exp) {
    for (auto i : variables) {
        replace(exp, i, variableAndMeaning[i]);
    }
    cout << "exp -> " << exp << "\n";
}

void Variables::initVariables() {
    for (auto i : variableAndMeaning) {
        variables.push_back(i.first);// Записываем все переменные в массив
    }
}

void Variables::replacementVariables() {
    for (int n = 0; n < variables.size(); ++n) {
        for (auto i : variableAndMeaning) {
            for (auto j : variables) {
                replace(variableAndMeaning[i.first], j, variableAndMeaning[j]);
                cout << "СТРОКА ПОСЛЕ REPLACE -> " << variableAndMeaning[i.first] << "\n";
            }
        }
    }
}


void Variables::convertVariablesToNumber() {
    Token tk;
    RPN rpn;
    for (auto i : variableAndMeaning) {
        cout << "\n-------------\n";
        string exp = i.second;
        cout << "ВХОДНОЕ ВЫРАЖЕНИЕ: " << exp << "\n";
        auto g = rpn.toPostfix(tk, exp);
        cout << "ВЫРАЖЕНИЕ В ПОСТФИКСНОЙ ФОРМЕ: ";
        for (auto k : g) cout << k << " ";
        cout << "\n\n";
        if (!g.empty()) {
            auto p = rpn.calcRPN(g);
            string str = rpn.convertComplex2String(p.top());
            variableAndMeaning[i.first] = str;
            cout << "ПРЕОБРАЗОВАННОЕ ВЫРАЖЕНИЕ В ЧИСЛО: " << variableAndMeaning[i.first] << "\n";
        }
        cout << "\n-------------\n";
    }
}