#pragma once

#include <vector>
#include <iostream>

class Vector3f {
    public:
        // (1) Constructor
        Vector3f();
        // (2) Destructor
        ~Vector3f();
        // (3) Copy Constructor
        Vector3f(const Vector3f& rhs);
        // (3) and (4) Copy Assignment Operator
        Vector3f& operator= (const Vector3f& rhs);
 	    Vector3f operator+ (const Vector3f& rhs) const;
        
        // preincrement operator
        Vector3f& operator++();

        friend std::ostream& operator<<(std::ostream& os, const Vector3f& obj);

        void PrintData();

        float x, y, z;
};
