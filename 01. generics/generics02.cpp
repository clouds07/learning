// Program converted to C++
// with commencts changed to one line
// io changed to iostream
// and so on...
// maintained the number of parameters for the summing function

#include <iostream>
#include <vector>

using namespace std;

static const int vectorLen = 40;

template <class summable>
inline void displayVector(const vector<summable> array, int array_len = 0)
{
    int i = 0;
    for (i = 0; i < array_len-1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[i] << endl;
}

int main(void)
{
    vector<int> vectorInt;
    vector<double> vectorDbl;

    for (int i = 0; i < vectorLen; ++i) {
        vectorInt.push_back(i);
        vectorDbl.push_back(i + 0.35);
    }

    cout << "Integers vector: ";
    displayVector(vectorInt, vectorInt.size());
    cout << "Doubles vector: ";
    displayVector(vectorDbl, vectorDbl.size());
}