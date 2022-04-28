#include "Vector.h"

std::string *Vector::increaseVectorString() {
    size *= 2;
    std::string *arr = new std::string[size];
    std::memcpy(arr, arrString, index * sizeof(std::string));
    delete[] arrString;
    return arr;
}

void Vector::push_back(std::string variable) {
    if (index == size) {
        arrString = increaseVectorString();
    }
    arrString[index] = variable;
    index++;
}

void Vector::printVectorString() {
    std::cout << "Vector String: ";
    for (int i = 0; i < index; ++i) {
        std::cout << arrString[i] << " -> ";
    }
    std::cout << "Size: " << size << "\n";
}

int *Vector::increaseVectorInt() {
    size *= 2;
    int *arr = new int[size];
    std::memcpy(arr, arrInt, index * sizeof(int));
    delete[] arrInt;
    return arr;
}

void Vector::push_back(int variable) {
    if (index == size) {
        arrInt = increaseVectorInt();
    }
    arrInt[index] = variable;
    index++;
}

void Vector::printVectorInt() {
    std::cout << "Vector Int: ";
    for (int i = 0; i < index; ++i) {
        std::cout << arrInt[i] << " -> ";
    }
    std::cout << "Size: " << size << "\n";
}
