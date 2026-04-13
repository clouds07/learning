#include "Vector3f.hpp"
#include <iostream>

Vector3f::Vector3f() {
    std::cout << "Constructor" << std::endl;
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vector3f::~Vector3f() {
}

Vector3f::Vector3f(const Vector3f& rhs) {
    std::cout << "Copy Constructor" << std::endl;
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
}

Vector3f& Vector3f::operator= (const Vector3f& rhs) {
    std::cout << "Copy Assignment Operator" << std::endl;    
    if (this == &rhs) {
        return *this;
    }
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

Vector3f Vector3f::operator+ (const Vector3f& rhs) const {
    std::cout << "Arithmetic Operator" << std::endl;    
    Vector3f result;
    result.x = this->x + rhs.x;
    result.y = this->y + rhs.y;
    result.z = this->z + rhs.z;
    return result;
}

Vector3f& Vector3f::operator++() {
    x = x + 1.0f;
    y = y + 1.0f;
    z = z + 1.0f;

    return *this;
}

/*
bool Vector3f::operator==(const Vector3f& rhs) const {
    std::cout << "part of class " << std::endl;
    return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
}
*/

void Vector3f::PrintData() {
    std::cout << "Vector3f data: ";
    std::cout << x << " " << y << " " << z << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Vector3f& obj)
{
    os << obj.x << ", " << obj.y << ", " << obj.z;
    return os;
}
