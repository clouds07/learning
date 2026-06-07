#include <iostream>
#include <span>
#include <array>
#include <vector>

/* void PrintArray(const std::array<int, 4>& arr) {
    for (auto& elem: arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}*/

void PrintArray(const std::span<int>& param) {

    if (std::dynamic_extent == param.extent)
        std::cout << "dynamic extent\n";
    else
        std::cout << "static extent = " << param.extent << '\n';

    for (auto& elem: param) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::array<int, 4> arr {1, 2, 3, 4};
    std::span mySpan{arr};

    std::cout << mySpan.extent << "\n";

    PrintArray(arr);
    PrintArray(mySpan);

    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};

    PrintArray(std::span(vec.begin() + 3, 3));

    return 0;
}
