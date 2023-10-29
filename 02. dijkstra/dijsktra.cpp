// Implementation of the Dijsktra algorithm

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

constexpr int graphSize = 15;
constexpr double density = 0.40f;

// Static function used to create the graph
static double prob()
{
    double prob_ = rand() % 100;

    prob_ /= 100.;

    return prob_;
}

bool isEqual(const pair<int, int>& element)
{
    return element.first == 0;
}

// This function searches through a set of <node, cost> for a given node
// Returns true if the node exists in the set
bool find(vector<pair<int, int>> &searchSet, int node)
{
    for(auto &elem : searchSet)
    {
        if (elem.first == node)
        {
            return true;
        }
    }
    return false;
}

// Graph class definition
class graph
{
public:
    graph(int size, double density = 0.19, int maxCost = 10);
    ~graph();

    void minimumCostPath(int nodeA, int nodeB);

protected:
    int** graph_;

    int graphSize;
    int maxEdgeCost;
    double graphDensity;
};

// Class constructor - takes as parameters the  graph size,
// the graph density and the maximum cost (random generated)
graph::graph(int size, double density, int maxCost)
{
    graphSize = size;
    maxEdgeCost = maxCost;
    graphDensity = density;

    graph_ = new int*[graphSize];

    for (int i = 0; i < graphSize; ++i) {
        graph_[i] = new int[graphSize];
    }

    // Generate a graph, with a defined density
    for (int i = 0; i < graphSize; ++i) {
        for (int j = 0; j < graphSize; ++j) {
            if (i == j) {
                // No path from node to self
                graph_[i][j] = 0;
            } else {
                if (prob() < density) {
                    // Initialize edges with random cost
                    graph_[i][j] = rand() % 11;
                } else {
                    // Initialize no edge with zero
                    graph_[i][j] = 0;
                }
            }
        }
    }

    // Graphical representation of the graph
    for (int i = 0; i < graphSize; ++i) {
        for (int j = 0; j < graphSize; ++j) {
            cout << graph_[i][j] << " ";
        }
        cout << endl;
    }

}

// Class destructor
graph::~graph()
{
    // Free the allocated memory
    for (int i = 0; i < graphSize; ++i) {
        delete[] graph_[i];
    }

    delete[] graph_;
}

// Computes the minimum cost path between node A and node B
// using Dijkstra's algorithm
void graph::minimumCostPath(int nodeA, int nodeB)
{
    int oldSize = 0, cSize = 0;
    bool* closedSetNodes = new bool[graphSize];
    bool* openSetNodes = new bool[graphSize];

    vector<int> allNodes;                       // Set of all the nodes
    vector<pair<int, int>> closedSet;           // Set of nodes that have known shortest distances
    vector<pair<int, int>> openSet;             // Set of nodes that are reachable

    if ((nodeA > graphSize) || (nodeB > graphSize))
    {
        cout << "Invalid node values" << endl;
        return;
    }

    for (int i = 0; i < graphSize; ++i)
    {
        openSetNodes[i] = closedSetNodes[i] = false;
    }

    closedSetNodes[nodeA] = true;
    closedSet.push_back(make_pair(nodeA, 0));

    int nodeIndex = 0;
    int currentNode = nodeA;

    do 
    {
        // Add all accessible nodes to the open set
        for (int j = 0; j < graphSize; ++j)
        {
            if ((graph_[currentNode][j] != 0) &&
                !find(closedSet, j) &&
                !find(openSet, j))
            {
                openSet.push_back(make_pair(j, graph_[currentNode][j]));
            }
        }

        // No nodes in the open set, so no path found
        if (!openSet.size())
        {
            cout << "No path found" << endl;
            return;
        }

        // Choose the node with the least cost, from the open set
        int minCost = numeric_limits<int>::max();
        for (auto elem = openSet.begin(); elem < openSet.end(); ++elem)
        {
            if (elem->second < minCost)
            {
                minCost = elem->second;
                nodeIndex = distance(openSet.begin(), elem);
            }
        }

        // Add node to the closed set
        closedSet.push_back(make_pair(openSet.at(nodeIndex).first, openSet.at(nodeIndex).second));
        openSet.erase(openSet.begin() + nodeIndex);

        currentNode = closedSet.back().first;
    } while (currentNode != nodeB);

    cout << "Found a path: " << endl;

    for(const auto &elem : closedSet)
    {
        cout << elem.first << " ";
    }
    cout << endl;

    // Cleanup
    delete[] closedSetNodes;
    delete[] openSetNodes;
}

int main(void)
{
    // Initialize the random generator
    srand(time(0));

    graph testGraph(graphSize, density);

    testGraph.minimumCostPath(1, 4);

    testGraph.minimumCostPath(2, 13);
}
