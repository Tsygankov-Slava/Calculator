#pragma once

#include <iostream>
#include <set>
#include <string>

struct Token {
    static std::string readToken(std::string const &token, int &index);
};
