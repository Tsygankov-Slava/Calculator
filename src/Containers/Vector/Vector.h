#pragma once

#include <cstring>
#include <iostream>
#include <string>

struct Vector {
public:
    int size = 100;
    int index = 0;

    int *arrInt = new int[size];
    std::string *arrString = new std::string[size];

public:
    void push_back(std::string variable);
    void push_back(int variable);

    std::string *increaseVectorString();
    int *increaseVectorInt();

    void printVectorString();
    void printVectorInt();
};
