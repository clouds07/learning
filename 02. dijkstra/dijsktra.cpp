// Implementation of the Dijsktra algorithm

#include <iostream>
#include <vector>

using namespace std;


class edge {
    int node1;
    int node2;
    int cost;
};

vector<int> allNodes;       // Set of all the nodes
vector<int> closedNodes;    // Set of nodes that have known shortest distances
vector<int> openNodes;      // Set of nodes that are reachable


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