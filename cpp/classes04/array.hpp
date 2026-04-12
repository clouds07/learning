#include <vector>

class Array {
    public:
        // (1) Constructor
        Array();
        // (2) Destructor
        ~Array();
        // (3) Copy Constructor
        Array(const Array& rhs);
        // (4) Copy Assignment Operator
        Array& operator= (const Array& rhs);

        void PrintData();
        void SetData(int index, int value);

    private:
        std::vector<unsigned int> data;
}