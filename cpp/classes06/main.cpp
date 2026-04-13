#include <iostream>
#include "Vector3f.hpp"

bool operator==(const Vector3f& lhs, const Vector3f& rhs) {
    return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
}


int main(int argc, char** argv) {
    Vector3f myVector;
                myVector.x = 1.0f;
                myVector.y = 2.0f;
                myVector.z = 3.0f;

    Vector3f myVector2;
                myVector2.x = 1.0f;
                myVector2.y = 2.0f;
                myVector2.z = 3.0f;

    Vector3f result;

    std::cout << (myVector==myVector2) << std::endl;

    myVector = myVector + myVector2;

    std::cout << myVector << std::endl;
    ++myVector;
    std::cout << myVector << std::endl;
    std::cout << myVector2 << std::endl;

    std::cout << (myVector==myVector2) << std::endl;

    return 0;
}
