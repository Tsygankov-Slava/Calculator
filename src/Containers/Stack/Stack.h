#pragma once

#include <string>

struct Stack {
public:
    std::string variable;
    Stack* next;

public:
    void push(std::string variable);
    void pop();
    int size_();
    bool empty();
};
