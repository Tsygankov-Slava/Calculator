#pragma once

#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <stack>
#include <string>

#include "../Containers/Vector/Vector.h"
#include "../Debug/Debug.h"
#include "../Token/Token.h"
#include "../Variables/Variables.h"

struct RPN {
    std::map<const std::string, const std::string> CONSTANTS = {{"PI", std::to_string(M_PI)},
                                                                {"E", std::to_string(M_E)}};

    std::map<const std::string, const int> operationWeights = {{"(", 0},
                                                               {"+", 1},
                                                               {"-", 1},
                                                               {"*", 2},
                                                               {"/", 2},
                                                               {"^", 3},
                                                               {"_", 4},
                                                               {"phase", 5},
                                                               {"mag", 5},
                                                               {"sin", 5},
                                                               {"cos", 5},
                                                               {"log", 5},
                                                               {"sqrt", 5},
                                                               {"real", 5},
                                                               {"imag", 5},
                                                               {"exp", 5}};
    static bool isNumber(std::string &token);
    static bool isVariable(std::string &token, struct Variables var);
    static std::complex<double> atoc(std::string a);
    static std::string convertComplex2String(std::complex<double> a);
    Vector toPostfix(const std::string &expression, Variables &var);
    static std::stack<std::complex<double>> calcRPN(Vector expRPN);
};
