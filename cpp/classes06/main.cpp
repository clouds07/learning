#include <iostream>
#include "Vector3f.hpp"

bool operator==(const Vector3f& lhs, const Vector3f& rhs) {
    std::cout << "non-member function " << std::endl;
    return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
}


int main(int argc, char** argv) {
    Vector3f myVector;
                myVector.x = 1.f;
                myVector.y = 1.f;
                myVector.z = 1.f;

    Vector3f myVector2;
                myVector2.x = 0.999999999999f;
                myVector2.y = 0.999999999999f;
                myVector2.z = 0.999999999999f;

    Vector3f result;

    if (myVector==myVector2) {
        std::cout << "Vectors are equal" << std::endl;
    } else {
        std::cout << "Vectors are NOT equal" << std::endl;
    }

    myVector = myVector + myVector2;

    std::cout << myVector << std::endl;
    ++myVector;
    std::cout << myVector << std::endl;
    std::cout << myVector2 << std::endl;

    std::cout << (myVector==myVector2) << std::endl;

    return 0;
}
