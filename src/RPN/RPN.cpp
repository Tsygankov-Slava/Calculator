#include "RPN.h"

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

std::vector<std::string> RPN::toPostfix(const std::string &expression) {
    int index = 0, sizeExp = expression.size();
    bool may_unary = true;
    std::string token;
    std::vector<std::string> result;
    std::stack<std::string> stackOperations;
    while (index < sizeExp) {
        token = "";
        token = Token::readToken(expression, index);
        if (CONSTANTS.count(token)) {
            token = CONSTANTS[token];
        }
        Debug::printToken(token);
        if (isNumber(token)) {
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

std::stack<std::complex<double>> RPN::calcRPN(std::vector<std::string> expRPN) {
    std::stack<std::complex<double>> result;
    std::set<std::string> operations = {"+", "-", "*", "/", "^"};
    std::set<std::string> functions = {"_", "sin", "cos", "log", "sqrt", "exp", "real", "imag"};
    for (std::string &x : expRPN) {
        if (isNumber(x)) {
            result.push(atoc(x));
        } else if (operations.contains(x)) {
            std::complex<double> a, b;
            b = result.top();
            result.pop();
            a = result.top();
            result.pop();
            if (x == "+") {
                Debug::printOperationPlus(a, b);
                result.push(a + b);
            } else if (x == "-") {
                Debug::printOperationMinus(a, b);
                result.push(a - b);
            } else if (x == "*") {
                Debug::printOperationMultiply(a, b);
                result.push(a * b);
            } else if (x == "/") {
                Debug::printOperationDivision(a, b);
                result.push(a / b);
            } else if (x == "^") {
                Debug::printOperationDegree(a, b);
                result.push(pow(a, b));
            }
        } else if (functions.contains(x)) {
            std::complex<double> a;
            a = result.top();
            result.pop();
            if (x == "_") {
                result.push(-a);
                Debug::printOperationUnMinus(a);
            } else if (x == "sin") {
                result.push(sin(a));
                Debug::printOperationSin(a);
            } else if (x == "cos") {
                result.push(cos(a));
                Debug::printOperationCos(a);
            } else if (x == "log") {
                result.push(log(a));
                Debug::printOperationLog(a);
            } else if (x == "sqrt") {
                result.push(sqrt(a));
                Debug::printOperationSqrt(a);
            } else if (x == "exp") {
                result.push(exp(a));
                Debug::printOperationExp(a);
            } else if (x == "real") {
                result.push(real(a));
                Debug::printOperationReal(a);
            } else if (x == "imag") {
                result.push(imag(a));
                Debug::printOperationImag(a);
            }
        }
    }
    return result;
}

std::string RPN::convertComplex2String(std::complex<double> a) {
    if (std::fabs(a.imag()) < 1e10) {
        return std::to_string(a.real()) + " + " + std::to_string(a.imag()) + "i";
    }
    return std::to_string(a.real());
}