#include "Array.hpp"
#include <iostream>

Array::Array() {
    std::cout << "Constructor" << std::endl;
    for(int i = 0; i < 10; ++i) {
        data.push_back(i*i);
    }
}

Array::~Array() {
    //std::cout << "Destructor" << std::endl;
    //delete[] data;
    data.clear();
}

Array::Array(const Array& rhs) {
    std::cout << "Copy Constructor" << std::endl;
    for(int i = 0; i < rhs.data.size(); i++) {
    //for(const int i : rhs.data) {
        data.push_back(rhs.data[i]);
    }
}

Array& Array::operator= (const Array& rhs) {
    std::cout << "Copy Assignment Operator" << std::endl;    
    if (this == &rhs) {
        return *this;
    }
    for(const int i : rhs.data) {
        data[i] = rhs.data[i];
    }
    return *this;
}

void Array::PrintData() {
    std::cout << "Array data: ";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i + 1 < data.size()) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

void Array::SetData(size_t index, unsigned int value) {
    if (index >= data.size()) {
        std::cerr << "SetData: index out of range: " << index << std::endl;
        return;
    }
    data[index] = value;
}
