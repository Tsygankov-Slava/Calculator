#include "Arguments/Arguments.h"
#include "Command/Command.h"
#include "Containers/Vector/Vector.h"
#include "Debug/Debug.h"
#include "File/File.h"
#include "History/History.h"
#include "RPN/RPN.h"

int main(int argc, char *argv[]) {
    File file;
    Variables var;
    RPN rpn;
    Command cmd;
    History history;
    std::string exp;

    Arguments arguments;
    arguments.checkArguments(argc, argv, exp, file);

    std::cout << "Чтобы получить информацию по пользованию введите команду help()\n";
    while (true) {
        file.checkFileVariablesAccess(var);
        file.checkFileHistoryAccess();

        Debug::printSourceExpressions(var);

        var.initVariables();

        Debug::printAllVariables(var);

        var.ReplacementVariables();

        Debug::printExpressionsAfterReplacement(var);

        bool expIsArg = false;
        if (exp.empty()) {
            std::cout << ">>> ";
            std::getline(std::cin, exp);
            if (exp == "exit()") {
                std::cout << "\tКалькулятор закончил работу!\n";
                return 0;
            }
            if (exp == "clear()") {
                system("clear");
                exp = "";
                std::cout << "Чтобы получить информацию по пользованию введите команду help()\n";
                continue;
            }
            try {
                if (cmd.isCommand(exp, var, file, history)) {
                    exp = "";
                    continue;
                }
            } catch (const std::invalid_argument& error) {
                std::cout << error.what() << "\n";
                exp = "";
                continue;
            }
        } else {
            std::cout << "Полученное выражение -> " << exp << "\n";
            expIsArg = true;
        }

        if (!exp.empty()) {
            if (var.variableDefinition(exp)) {
                file.addVariable(exp);
            } else {
                try {
                    var.changeVariablesInExpression(exp);
                    auto g = rpn.toPostfix(exp, var);
                    std::cout << "\n";
                    auto p = RPN::calcRPN(g);
                    std::cout << "--> " << RPN::convertComplex2String(p.top());
                    if (file.checkFileHistoryAccess()) {
                        history.inHistory(file.pathHistory, exp + " = " + RPN::convertComplex2String(p.top()));
                    }
                } catch (const std::invalid_argument& error) {
                    std::cout << error.what();
                }
            }
            std::cout << "\n";
            exp = "";
            if (expIsArg) {
                break;
            }
        }
    }
}
