#include <iostream>


int main() {
    int* array = new int[100];
    for (auto i = 0; i < sizeof(array); ++i) {
        array[i] = i;
    }

    int* ptr = array;
    std::cout << "*ptr: " << *ptr << "\n";

    delete[] array;

    // Create a second pointer
    int* ptr2 = ptr;

    std::cout << "*ptr2: " << *ptr2 << "\n";

    return 0;
}
