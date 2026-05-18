#include <iostream>
#include <initializer_list>

struct UDT {
    UDT(int a, int b, int c) {
        std::cout << "constructor with 3 params\n";
    }

    UDT(std::initializer_list<int> data) : m_data (data) {
        std::cout << "initializer_list constructor\n";
    }

    ~UDT() {
    }

    void PrintData() {
        for (auto &e : m_data) {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }
private:
    std::initializer_list<int> m_data;
};

int main(int argc, char** argv) {
    UDT u{1, 2, 3};
    u.PrintData();

    UDT u2(1, 2, 3);
    u2.PrintData();

    return 0;
}
