#include "Debug.h"

void Debug::printSourceExpressions(Variables &var) {
    if (isDebug) {
        cout << "\n--Исходные выражения--\n";
        for (auto &i : var.variableAndMeaning) cout << i.first << "=" << i.second << "\n";
        cout << "----\n\n";
    }
}
void Debug::printAllVariables(Variables &var) {
    if (isDebug) {
        cout << "\n--Все переменные--\n";
        for (auto &i : var.variables) cout << i << " ";
        cout << "\n----\n\n";
    }
}
void Debug::printExpressionsAfterReplacement(Variables &var) {
    if (isDebug) {
        cout << "-----Выражения после замены----\n";
        for (auto &i : var.variableAndMeaning) cout << i.first << " " << i.second << "\n";
        cout << "---------\n";
    }
}

void Debug::printToken(string &token) {
    cout << "Token -> " << token << "\n";
}

void Debug::printOperationPlus(complex<double> &a, complex<double> &b) {
    cout << "Сложение равно: " << a + b << "| a = " << a << ", b = " << b << "\n";
}

void Debug::printOperationMinus(complex<double> &a, complex<double> &b) {
    cout << "Вычитание равно: " << a - b << "| a = " << a << ", b = " << b << "\n";
}

void Debug::printOperationMultiply(complex<double> &a, complex<double> &b) {
    cout << "Умножение равно: " << a * b << "| a = " << a << ", b = " << b << "\n";
}

void Debug::printOperationDivision(complex<double> &a, complex<double> &b) {
    cout << "Частное равно: " << a / b << "| a = " << a << ", b = " << b << "\n";
}

void Debug::printOperationDegree(complex<double> &a, complex<double> &b) {
    cout << "Возведение в степень равно: " << pow(a, b) << "| a = " << a << ", b = " << b << "\n";
}

void Debug::printOperationUnMinus(complex<double> &a) {
    cout << "Функция un_minus: " << -a << "| a = " << a << "\n";
}

void Debug::printOperationSin(complex<double> &a) {
    cout << "Функция sin: " << sin(a) << "| a = " << a << "\n";
}

void Debug::printOperationCos(complex<double> &a) {
    cout << "Функция cos: " << cos(a) << "| a = " << a << "\n";
}

void Debug::printOperationLog(complex<double> &a) {
    cout << "Функция log: " << log(a) << "| a = " << a << "\n";
}

void Debug::printOperationSqrt(complex<double> &a) {
    cout << "Функция sqrt: " << sqrt(a) << "| a = " << a << "\n";
}

void Debug::printOperationExp(complex<double> &a) {
    cout << "Функция exp: " << exp(a) << "| a = " << a << "\n";
}

void Debug::printOperationReal(complex<double> &a) {
    cout << "Функция real: " << real(a) << "| a = " << a << "\n";
}

void Debug::printOperationImag(complex<double> &a) {
    cout << "Функция imag: " << imag(a) << "| a = " << a << "\n";
}