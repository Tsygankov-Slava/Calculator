#pragma once

#include <complex>
#include <iostream>

#include "../Variables/Variables.h"
#include "../isDebug/isDebug.h"


using std::complex;
using std::cout;
using std::string;

typedef struct Variables Variables;

struct Debug {

    static void printSourceExpressions(Variables &var);
    static void printAllVariables(Variables &var);
    static void printExpressionsAfterReplacement(Variables &var);

    static void printToken(string &token);

    static void printOperationPlus(complex<double> &a, complex<double> &b);
    static void printOperationMinus(complex<double> &a, complex<double> &b);
    static void printOperationMultiply(complex<double> &a, complex<double> &b);
    static void printOperationDivision(complex<double> &a, complex<double> &b);
    static void printOperationDegree(complex<double> &a, complex<double> &b);
    static void printOperationUnMinus(complex<double> &a);

    static void printOperationSin(complex<double> &a);
    static void printOperationCos(complex<double> &a);
    static void printOperationLog(complex<double> &a);
    static void printOperationSqrt(complex<double> &a);
    static void printOperationExp(complex<double> &a);
    static void printOperationReal(complex<double> &a);
    static void printOperationImag(complex<double> &a);
};
