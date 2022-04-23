#pragma once

#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "../Token/Token.h"

using std::complex;
using std::cout;
using std::map;
using std::stack;
using std::string;
using std::to_string;
using std::vector;

struct RPN {
    map<const string, const string> CONSTANTS = {{"pi", to_string(M_PI)},
                                                 {"e", to_string(M_E)}};

    map<const string, const int> operationWeights = {{"(", 0},
                                                     {"+", 1},
                                                     {"-", 1},
                                                     {"*", 2},
                                                     {"/", 2},
                                                     {"^", 3},
                                                     {"_",4},
                                                     {"sin", 5},
                                                     {"cos", 5},
                                                     {"log", 5},
                                                     {"sqrt", 5},
                                                     {"real", 5},
                                                     {"imag", 5},
                                                     {"exp", 5}};
    bool isNumber(string &token);
    complex<double> atoc(string a);
    string convertComplex2String(complex<double> a);
    vector<string> toPostfix(Token tk, const string &expression);
    stack<complex<double>> calcRPN(vector<string> expRPN);
};
