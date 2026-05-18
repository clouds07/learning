#include <iostream>
#include <string>


int main() {
    std::string myString = "copy construct me";
    std::string newValue;

    std::cout << "myString: " << myString << "\n";
    std::cout << "newValue: " << newValue << "\n";

    // move semantics
    // std::move allows to 'steal' the value
    newValue = std::move(myString);
    
    // move assignment operator - explicit move semantics
    // newValue = static_cast<std::string&&>(myString);
    
    // Copy construction
    //newValue = myString;

    std::cout << "myString: " << myString << "\n";
    std::cout << "newValue: " << newValue << "\n";
    return 0;
}
