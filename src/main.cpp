#include "Containers/Vector/Vector.h"
#include "Debug/Debug.h"
#include "File/File.h"
#include "RPN/RPN.h"
#include "Arguments/Arguments.h"

int main(int argc, char *argv[]) {
    File file;
    Variables var;
    RPN rpn;

    std::string exp;

    Arguments arguments;
    arguments.checkArguments(argc, argv, exp, file);

    file.checkFileAccess(var);

    while (true) {
        if (exp.empty()) {
            std::cout << "Введите выражение -> ";
            std::getline(std::cin, exp);
            if (exp == "exit") {
                return 0;
            }
        } else {
            std::cout << "Полученное выражение -> " << exp << "\n";
        }

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
        exp = "";
    }
}
