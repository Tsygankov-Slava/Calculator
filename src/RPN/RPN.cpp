#include "RPN.h"

bool RPN::isNumber(string &token) {
    for (auto &i : token) {
        if ((i < '0' || i > '9') && i != '.' && i != 'i') {
            return false;
        }
    }
    return true;
}

complex<double> RPN::atoc(string a) {
    complex<double> result;
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

vector<string> RPN::toPostfix(Token tk, const string &expression) {
    int index = 0, sizeExp = expression.size();
    bool may_unary = true;
    string token;
    vector<string> result;
    stack<string> stackOperations;
    while (index < sizeExp) {
        token = "";
        token = tk.readToken(expression, index);
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
                    cout << "ОШИБКА: НЕ НАШЛОСЬ ЛЕВОЙ СКОБКИ\n";
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

stack<complex<double>> RPN::calcRPN(vector<string> expRPN) {
    stack<complex<double>> result;
    set<string> operations = {"+", "-", "*", "/", "^"};
    set<string> functions = {"sin", "cos", "log", "sqrt", "exp", "real", "imag"};
    for (string &x : expRPN) {
        if (isNumber(x)) {
            result.push(atoc(x));
        } else if (operations.contains(x)) {
            complex<double> a, b;
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
            complex<double> a;
            a = result.top();
            result.pop();
            if (x == "_") {
                result.push(-a);
                Debug::printOperationUnMinus(a);
                cout << "Функция un_minus: " << -a << "| a = " << a << "\n";
            } else if (x == "sin") {
                result.push(sin(a));
                Debug::printOperationSin(a);
                cout << "Функция sin: " << sin(a) << "| a = " << a << "\n";
            } else if (x == "cos") {
                result.push(cos(a));
                Debug::printOperationCos(a);
                cout << "Функция cos: " << cos(a) << "| a = " << a << "\n";
            } else if (x == "log") {
                result.push(log(a));
                Debug::printOperationLog(a);
                cout << "Функция log: " << log(a) << "| a = " << a << "\n";
            } else if (x == "sqrt") {
                result.push(sqrt(a));
                Debug::printOperationSqrt(a);
                cout << "Функция sqrt: " << sqrt(a) << "| a = " << a << "\n";
            } else if (x == "exp") {
                result.push(exp(a));
                Debug::printOperationExp(a);
                cout << "Функция exp: " << exp(a) << "| a = " << a << "\n";
            } else if (x == "real") {
                result.push(real(a));
                Debug::printOperationReal(a);
                cout << "Функция real: " << real(a) << "| a = " << a << "\n";
            } else if (x == "imag") {
                result.push(imag(a));
                Debug::printOperationImag(a);
                cout << "Функция imag: " << imag(a) << "| a = " << a << "\n";
            }
        }
    }
    return result;
}

string RPN::convertComplex2String(complex<double> a) {
    string result = std::to_string(std::real(a));
    if (std::imag(a) != 0) {
        result = result + "+" + std::to_string(std::imag(a)) + "i";
    }
    return result;
}