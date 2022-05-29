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

std::string *Vector::delElement(Vector &var, std::string &el) {
    std::string *arrNew = new std::string[var.size];
    int count = 0;
    for (int i = 0; i < var.index; ++i) {
        if (var.arrString[i] != el) {
            arrNew[count] = var.arrString[i];
            ++count;
        }
    }
    delete[] var.arrString;
    var.index = count;
    return arrNew;
}