#include "Debug/Debug.h"
#include "File/File.h"
#include "RPN/RPN.h"
#include "Token/Token.h"
#include "isDebug/isDebug.h"

int main(int argc, char *argv[]) {
    if (argc > 1 && std::strcmp(argv[1], "-d") == 0) {
        isDebug = true;
    }

    File file;
    Variables var;
    RPN rpn;

    var.variableAndMeaning = file.getText();
    if (var.variableAndMeaning.empty()) {
        std::cout << "File can't open.";
        return 0;
    }

    Debug::printSourceExpressions(var);

    var.initVariables();

    Debug::printAllVariables(var);

    var.replacementVariables();

    Debug::printExpressionsAfterReplacement(var);

    var.convertVariablesToNumber();

    std::string exp = "exp((-i)*(pi)*(alpha)*(len)/v0)";
    if (!exp.empty()) {
        var.changeVariablesInExpression(exp);
        auto g = rpn.toPostfix(exp);
        std::cout << "\n";
        auto p = RPN::calcRPN(g);
        std::cout << RPN::convertComplex2String(p.top());
    }
    return 0;
}
