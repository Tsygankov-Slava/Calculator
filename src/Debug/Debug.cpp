#include "Debug.h"

void Debug::printSourceExpressions(Variables &var) {
    if (isDebug) {
        std::cout << "\n--Исходные выражения--\n";
        for (auto &i : var.variableAndMeaning) std::cout << i.first << "=" << i.second << "\n";
        std::cout << "----\n\n";
    }
}
void Debug::printAllVariables(Variables &var) {
    if (isDebug) {
        std::cout << "\n--Все переменные--\n";
        for (int i = 0; i < var.variables.index; ++i) std::cout << var.variables.arrString[i] << " ";
        std::cout << "\n----\n\n";
    }
}
void Debug::printExpressionsAfterReplacement(Variables &var) {
    if (isDebug) {
        std::cout << "-----Выражения после замены----\n";
        for (auto &i : var.variableAndMeaning) std::cout << i.first << " " << i.second << "\n";
        std::cout << "---------\n";
    }
}

void Debug::printToken(std::string &token) {
    if (isDebug) {
        std::cout << "Token -> " << token << "\n";
    }
}

void Debug::printOperationPlus(std::complex<double> &a, std::complex<double> &b) {
    if (isDebug) {
        std::cout << "Сложение равно: " << a + b << "| a = " << a << ", b = " << b << "\n";
    }
}

void Debug::printOperationMinus(std::complex<double> &a, std::complex<double> &b) {
    if (isDebug) {
        std::cout << "Вычитание равно: " << a - b << "| a = " << a << ", b = " << b << "\n";
    }
}

void Debug::printOperationMultiply(std::complex<double> &a, std::complex<double> &b) {
    if (isDebug) {
        std::cout << "Умножение равно: " << a * b << "| a = " << a << ", b = " << b << "\n";
    }
}

void Debug::printOperationDivision(std::complex<double> &a, std::complex<double> &b) {
    if (isDebug) {
        std::cout << "Частное равно: " << a / b << "| a = " << a << ", b = " << b << "\n";
    }
}

void Debug::printOperationDegree(std::complex<double> &a, std::complex<double> &b) {
    if (isDebug) {
        std::cout << "Возведение в степень равно: " << pow(a, b) << "| a = " << a << ", b = " << b << "\n";
    }
}

void Debug::printOperationUnMinus(std::complex<double> &a) {
    if (isDebug) {
        std::cout << "Функция un_minus: " << -a << "| a = " << a << "\n";
    }
}

void Debug::printOperationSin(std::complex<double> &a) {
    if (isDebug) {
        std::cout << "Функция sin: " << sin(a) << "| a = " << a << "\n";
    }
}

void Debug::printOperationCos(std::complex<double> &a) {
    if (isDebug) {
        std::cout << "Функция cos: " << cos(a) << "| a = " << a << "\n";
    }
}

void Debug::printOperationLog(std::complex<double> &a) {
    if (isDebug) {
        std::cout << "Функция log: " << log(a) << "| a = " << a << "\n";
    }
}

void Debug::printOperationSqrt(std::complex<double> &a) {
    if (isDebug) {
        std::cout << "Функция sqrt: " << sqrt(a) << "| a = " << a << "\n";
    }
}

void Debug::printOperationExp(std::complex<double> &a) {
    if (isDebug) {
        std::cout << "Функция exp: " << exp(a) << "| a = " << a << "\n";
    }
}

void Debug::printOperationReal(std::complex<double> &a) {
    if (isDebug) {
        std::cout << "Функция real: " << real(a) << "| a = " << a << "\n";
    }
}

void Debug::printOperationImag(std::complex<double> &a) {
    if (isDebug) {
        std::cout << "Функция imag: " << imag(a) << "| a = " << a << "\n";
    }
}