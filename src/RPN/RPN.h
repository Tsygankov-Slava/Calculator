#pragma once

#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "../Debug/Debug.h"
#include "../Token/Token.h"

struct RPN {
    std::map<const std::string, const std::string> CONSTANTS = {{"pi", std::to_string(M_PI)},
                                                                {"e", std::to_string(M_E)}};

    std::map<const std::string, const int> operationWeights = {{"(", 0},
                                                               {"+", 1},
                                                               {"-", 1},
                                                               {"*", 2},
                                                               {"/", 2},
                                                               {"^", 3},
                                                               {"_", 4},
                                                               {"sin", 5},
                                                               {"cos", 5},
                                                               {"log", 5},
                                                               {"sqrt", 5},
                                                               {"real", 5},
                                                               {"imag", 5},
                                                               {"exp", 5}};
    static bool isNumber(std::string &token);
    static std::complex<double> atoc(std::string a);
    static std::string convertComplex2String(std::complex<double> a);
    std::vector<std::string> toPostfix(const std::string &expression);
    static std::stack<std::complex<double>> calcRPN(std::vector<std::string> expRPN);
};
