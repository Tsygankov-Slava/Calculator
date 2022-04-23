#include "File/File.h"
#include "RPN/RPN.h"
#include "Token/Token.h"
#include "Variables/Variables.h"

int main() {
    File file;
    Variables var;
    Token tk;
    RPN rpn;
    var.variableAndMeaning = file.getText();

    cout << "\n--Исходные выражения--\n";
    for (auto i : var.variableAndMeaning) cout << i.first << "=" << i.second << "\n";
    cout << "----\n\n";

    var.initVariables();

    cout << "\n--Все переменные--\n";
    for (auto i : var.variables) cout << i << " ";
    cout << "\n----\n\n";

    var.replacementVariables();

    cout << "-----Выражения после замены----\n";
    for (auto i : var.variableAndMeaning) cout << i.first << " " << i.second << "\n";
    cout << "---------\n";

    var.convertVariablesToNumber();

    cout << "------\n";
    string exp = "exp(-i*pi*alpha*len/v0)";
    cout << exp << "\n";
    if (!exp.empty()) {
        var.changeVariablesInExpression(exp);
        auto g = rpn.toPostfix(tk, exp);
        for (auto i : g) cout << i << " ";
        cout << "\n";
        auto p = rpn.calcRPN(g);
        cout << rpn.convertComplex2String(p.top());
    } else {
        cout << "Пустое выражение!";
        exit(0);
    }
    return 0;
}

