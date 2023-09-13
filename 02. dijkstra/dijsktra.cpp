// Implementation of the Dijsktra algorithm

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

constexpr int vectorLen = 40;
constexpr int graphSize = 40;
constexpr double density = 0.19f;

// Static function used to create the graph
static double prob()
{
    double prob_ = rand() % 100;

    prob_ /= 100.;

    return prob_;
}

// Static function used to set the edge costs
static int randCost()
{
    return rand() % 11;
}

bool isEqual(const std::pair<int, int>& element)
{
    return element.first == 0;
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
    cout << "Constructor execution" << endl;
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
                    graph_[i][j] = randCost();
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
    cout << "Destructor execution" << endl;

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
    int minCost = numeric_limits<int>::max();
    bool* closedSetNodes = new bool[graphSize];
    bool* openSetNodes = new bool[graphSize];

    vector<int> allNodes;                       // Set of all the nodes
    vector<pair<int, int>> closedSet;           // Set of nodes that have known shortest distances
    vector<pair<int, int>> openSet;             // Set of nodes that are reachable

    for (int i = 0; i < graphSize; ++i)
    {
        openSetNodes[i] = closedSetNodes[i] = false;
    }

    closedSetNodes[nodeA] = true;

    closedSet.push_back(make_pair(nodeA, 0));

    int minCostNode;
    int currentNode = nodeA;


    for (int j = 0; j < graphSize; ++j)
    {
        find_if(openSet.begin(), openSet.end(), isEqual())

        if ((graph_[currentNode][j] != 0) && (j))
        {
            openSet.push_back(make_pair(j, graph_[currentNode][j]));
        }
    }


    for (int j = 0; j < graphSize; ++j)
    {

        if (graph_[currentNode][j] != 0)
        {
            // Add adjacent nodes to the Open Set
            openSetNodes[j] = true;

            // Choose the node with the least cost, from the open set
            if ((graph_[currentNode][j] != 0) && (minCost > graph_[currentNode][j]))
            {
                openSet.push_back(make_pair(currentNode, graph_[currentNode][j]));

                minCost = graph_[currentNode][j];
                minCostNode = j;
            }
        }
    }

    while (closedSet.size() < graphSize)
    {
        
    }

    // Cleanup
    delete[] closedSetNodes;
    delete[] openSetNodes;
}

int main(void)
{
    graph testGraph(graphSize, density);

    // Initialize the random generator
    srand(time(0));

    testGraph.minimumCostPath(1, 17);

    testGraph.minimumCostPath(10, 25);
}
