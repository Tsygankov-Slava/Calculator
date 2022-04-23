#include "Token.h"

string Token::readToken(string const &token, int &index) {
    string result{};
    while (token[index] == ' ') ++index;
    const set<char> separators{'\0', '(', ')', ' ', '+', '-', '/', '*', '^'};
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