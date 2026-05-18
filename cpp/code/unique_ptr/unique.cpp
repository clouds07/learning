#include <iostream>
#include <memory>       // unique_ptr

class UDT {
public:
    UDT() {
        std::cout << "User Data Type created\n";
    }

    ~UDT() {
        std::cout << "User Data Type destroyed\n";
    }
};

int main() {

    // Creating one unique pointer
    std::unique_ptr<UDT> myData = std::unique_ptr<UDT>(new UDT);

    // try to copy - not allowed
    //std::unique_ptr<UDT> myDataCopy = myData;
    // try to move - allowed
    std::unique_ptr<UDT> myDataCopy = std::move(myData);

    // Creating an array pointed to by one unique pointer
    // std::unique_ptr<UDT[]> myDataArray = std::unique_ptr<UDT[]>(new UDT[10]);
    
    // The equivalent of the line above - preferred syntax (Factory pattern):
    //std::unique_ptr<UDT[]> myDataArray = std::make_unique<UDT[]>(10);



    return 0;
}
