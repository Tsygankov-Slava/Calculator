#pragma once

#include <iostream>
#include <set>
#include <string>

using std::set;
using std::string;

struct Token {
    string readToken(string const &token, int &index);
};
