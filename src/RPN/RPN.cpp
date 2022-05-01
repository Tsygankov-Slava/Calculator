#include "RPN.h"

bool RPN::isVariable(std::string &token, Variables var) {
    for (int i = 0; i < var.variables.index; ++i) {
        if (token == var.variables.arrString[i]) {
            return true;
        }
    }
    return false;
}

bool RPN::isNumber(std::string &token) {
    for (auto &i : token) {
        if ((i < '0' || i > '9') && i != '.' && i != 'i') {
            return false;
        }
    }
    return true;
}

std::complex<double> RPN::atoc(std::string a) {
    std::complex<double> result;
    if (a[a.size() - 1] == 'i') {
        if (a.size() == 1) {
            result.imag(1);
        } else {
            result.imag(atof(a.c_str()));
        }
    } else {
        result.real(atof(a.c_str()));
    }
    return result;
}

Vector RPN::toPostfix(const std::string &expression, Variables &var) {
    int index = 0, sizeExp = expression.size();
    bool may_unary = true;
    std::string token;
    Vector result;
    std::stack<std::string> stackOperations;
    while (index < sizeExp) {
        token = "";
        token = Token::readToken(expression, index);
        if (CONSTANTS.count(token)) {
            token = CONSTANTS[token];
        }
        Debug::printToken(token);
        if (isVariable(token, var)) {
            result.push_back(var.variableAndMeaning[token]);
            may_unary = false;
        } else if (isNumber(token)) {
            result.push_back(token);
            may_unary = false;
        } else if (token == "(") {
            stackOperations.push("(");
            may_unary = true;
        } else if (token == ")") {
            while (stackOperations.top() != "(") {
                result.push_back(stackOperations.top());
                stackOperations.pop();
                if (stackOperations.empty()) {
                    std::cout << "ОШИБКА: НЕ НАШЛОСЬ ЛЕВОЙ СКОБКИ\n";
                    exit(1);
                }
            }
            may_unary = false;
            stackOperations.pop();
        } else {
            if (may_unary && token == "-") token = "_";
            while (!stackOperations.empty() && operationWeights[token] <= operationWeights[stackOperations.top()]) {
                result.push_back(stackOperations.top());
                stackOperations.pop();
            }
            may_unary = true;
            stackOperations.push(token);
        }
    }
    while (!stackOperations.empty()) {
        result.push_back(stackOperations.top());
        stackOperations.pop();
    }
    return result;
}

std::stack<std::complex<double>> RPN::calcRPN(Vector expRPN) {
    std::stack<std::complex<double>> result;
    std::set<std::string> operations = {"+", "-", "*", "/", "^"};
    std::set<std::string> functions = {"_", "phase", "mag", "sin", "cos", "log", "sqrt", "exp", "real", "imag"};
    for (int x = 0; x < expRPN.index; ++x) {
        if (isNumber(expRPN.arrString[x])) {
            result.push(atoc(expRPN.arrString[x]));
        } else if (operations.count(expRPN.arrString[x])) {
            std::complex<double> a, b;
            b = result.top();
            result.pop();
            a = result.top();
            result.pop();
            if (expRPN.arrString[x] == "+") {
                Debug::printOperationPlus(a, b);
                result.push(a + b);
            } else if (expRPN.arrString[x] == "-") {
                Debug::printOperationMinus(a, b);
                result.push(a - b);
            } else if (expRPN.arrString[x] == "*") {
                Debug::printOperationMultiply(a, b);
                result.push(a * b);
            } else if (expRPN.arrString[x] == "/") {
                Debug::printOperationDivision(a, b);
                result.push(a / b);
            } else if (expRPN.arrString[x] == "^") {
                Debug::printOperationDegree(a, b);
                result.push(pow(a, b));
            }
        } else if (functions.count(expRPN.arrString[x])) {
            std::complex<double> a;
            a = result.top();
            result.pop();
            if (expRPN.arrString[x] == "phase") {
                result.push(arg(a));
            } else if (expRPN.arrString[x] == "mag") {
                result.push(abs(a));
            } else if (expRPN.arrString[x] == "_") {
                result.push(-a);
                Debug::printOperationUnMinus(a);
            } else if (expRPN.arrString[x] == "sin") {
                result.push(sin(a));
                Debug::printOperationSin(a);
            } else if (expRPN.arrString[x] == "cos") {
                result.push(cos(a));
                Debug::printOperationCos(a);
            } else if (expRPN.arrString[x] == "log") {
                result.push(log(a));
                Debug::printOperationLog(a);
            } else if (expRPN.arrString[x] == "sqrt") {
                result.push(sqrt(a));
                Debug::printOperationSqrt(a);
            } else if (expRPN.arrString[x] == "exp") {
                result.push(exp(a));
                Debug::printOperationExp(a);
            } else if (expRPN.arrString[x] == "real") {
                result.push(real(a));
                Debug::printOperationReal(a);
            } else if (expRPN.arrString[x] == "imag") {
                result.push(imag(a));
                Debug::printOperationImag(a);
            }
        }
    }
    return result;
}

std::string RPN::convertComplex2String(std::complex<double> a) {
    std::string real = std::to_string(a.real());
    std::string imag = std::to_string(a.imag()) + "i";
    if (a.real() < 0) {
        real = "(" + real + ")";
    }
    if (a.imag() < 0) {
        imag = "(" + imag + ")";
    }
    if (std::fabs(a.imag()) < 1e20) {
        return real + " + " + imag;
    }
    return std::to_string(a.real());
}