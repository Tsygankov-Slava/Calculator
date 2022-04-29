#include "Containers/Vector/Vector.h"
#include "Debug/Debug.h"
#include "File/File.h"
#include "RPN/RPN.h"
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

    std::string exp;
    while (std::cout << "Введите выражение -> ", std::getline(std::cin, exp), (exp == "exit") ? 0 : 1) {
        Debug::printSourceExpressions(var);

        var.initVariables();

        Debug::printAllVariables(var);

        var.ReplacementVariables();

        Debug::printExpressionsAfterReplacement(var);
        if (!exp.empty()) {
            var.changeVariablesInExpression(exp);
            auto g = rpn.toPostfix(exp, var);
            std::cout << "\n";
            auto p = RPN::calcRPN(g);
            std::cout << "Ответ: " << RPN::convertComplex2String(p.top());
        }
        std::cout << "\n";
    }
    return 0;
}
