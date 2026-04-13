#include <iostream>
#include "Array.hpp"

void printAnArray(const Array& arr) {
    //Do nothing
    arr.PrintData();
}

int main(int argc, char** argv) {
    Array myArray;

    myArray.SetData(0, 110000);
    myArray.SetData(1, 1000);
    myArray.SetData(4, 6547);

    Array myArray2(myArray);

    //myArray.PrintData();
    //myArray2.PrintData();

    for(int i = 0; i < 100; ++i) {
        printAnArray(myArray);
    }

    return 0;
}
