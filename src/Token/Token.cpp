#include "Token.h"

std::string Token::readToken(std::string const &token, int &index) {
    std::string result{};
    while (token[index] == ' ') ++index;
    const std::set<char> separators{'\0', '(', ')', ' ', '+', '-', '/', '*', '^'};
    for (;; ++index) {
        if (separators.contains(token[index])) {
            if (result.empty()) {
                result = token[index];
                ++index;
            }
            return result;
        }
        result += token[index];
    }
}