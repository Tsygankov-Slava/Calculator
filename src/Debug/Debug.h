#pragma once

#include <complex>
#include <iostream>

#include "../Variables/Variables.h"
#include "../isDebug/isDebug.h"

typedef struct Variables Variables;

struct Debug {

    static void printSourceExpressions(Variables &var);
    static void printAllVariables(Variables &var);
    static void printExpressionsAfterReplacement(Variables &var);

    static void printToken(std::string &token);

    static void printOperationPlus(std::complex<double> &a, std::complex<double> &b);
    static void printOperationMinus(std::complex<double> &a, std::complex<double> &b);
    static void printOperationMultiply(std::complex<double> &a, std::complex<double> &b);
    static void printOperationDivision(std::complex<double> &a, std::complex<double> &b);
    static void printOperationDegree(std::complex<double> &a, std::complex<double> &b);
    static void printOperationUnMinus(std::complex<double> &a);

    static void printOperationSin(std::complex<double> &a);
    static void printOperationCos(std::complex<double> &a);
    static void printOperationLog(std::complex<double> &a);
    static void printOperationSqrt(std::complex<double> &a);
    static void printOperationExp(std::complex<double> &a);
    static void printOperationReal(std::complex<double> &a);
    static void printOperationImag(std::complex<double> &a);
};
