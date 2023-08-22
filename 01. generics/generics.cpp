// Program converted to C++
// with comments changed to one line
// io changed to iostream
// and so on...
// maintained the number of parameters for the summing function

#include <iostream>
#include <vector>

using namespace std;

static const int vectorLen = 40;

template <class summable>
inline void sum(summable * const result, const vector<summable> array, int array_len = 0)
{
    for (int i = 0; i < array_len; i++) {
        *result += array[i];
    }
}

int main(void)
{
    vector<int> vectorInt;
    vector<double> vectorDbl;

    for (int i = 0; i < vectorLen; ++i) {
        vectorInt.push_back(i);
        vectorDbl.push_back(i + 0.35);
    }

    int sumInt;
    sum(&sumInt, vectorInt, vectorInt.size());
    cout << "Vector Integer sum is " << sumInt << endl;

    double sumDbl;
    sum(&sumDbl, vectorDbl, vectorDbl.size());
    cout << "Vector Double sum is " << sumDbl << endl;
}