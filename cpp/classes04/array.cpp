#include "Array.hpp"
#include <iostream>

Array::Array() {
    std::cout << "Constructor: " << std::endl;
    for(int i = 0; i < 100000; i++) {
        data.push_back(i*i);
    }
}

Array::~Array() {
    std::cout << "Destructor: " << std::endl;
    //delete[] data;
    data.clear();
}

Array::Array(const Array& rhs){
    std::cout << "Copy Constructor: " << std::endl;
//    for(int i = 0; i < 10; i++) {
    for(const int i : rhs.data) {
        data.push_back(rhs.data[i]);
    }

}


int main(int argc, char** argv) {
    Array myArray;

    myArray.PrintData();
}