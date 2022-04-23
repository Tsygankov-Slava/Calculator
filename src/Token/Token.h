#pragma once

#include <iostream>
#include <set>
#include <string>

using std::set;
using std::string;

struct Token {
    static string readToken(string const &token, int &index);
};
