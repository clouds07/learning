// Graph

#include <iostream>
#include <vector>

using namespace std;

static const int graphSize = 40;
static const double density = 0.19f;

class list_element {
    public:
        list_element():head(nullptr), cursor(nullptr){}


    private:
        list_element* head;
        list_element* cursor;
};

// Static function used to create the graph
static double prob()
{
    double prob_ = rand() % 100;

    prob_ /= 100.;

    return prob_;
}

// Static function used to set the edge costs
static int cost()
{
    return rand() % 11;
}

vector<int> allNodes;       // Set of all the nodes
vector<int> closedNodes;    // Set of nodes that have known shortest distances
vector<int> openNodes;      // Set of nodes that are reachable

// Template function
template <class summable>
inline void sum(summable * const result, const vector<summable> array, int array_len = 0)
{
    for (int i = 0; i < array_len; i++) {
        *result += array[i];
    }
}

bool is_connected(bool* graph[], int g_size)
{
    int old_size = 0, c_size = 0;
    bool* closed_set = new bool[g_size];
    bool* open_set = new bool[g_size];

    for (int i = 0; i < g_size; ++i)
    {
        open_set[i] = closed_set[i] = false;
    }

    open_set[0] = true;


    while (c_size < g_size)
    {
        for (int i = 0; i < g_size; ++i)
        {
            old_size = c_size;

            // Update the clsoed set with a node from the open set, if it's not already there
            if (open_set[i] && (closed_set[i] == false))
            {
                closed_set[i] = true;
                c_size++;

                // Update the open set
                for (int j = 0; j < g_size; ++j)
                {
                    // if there is an edge (i,j) in the graph
                    open_set[j] = open_set[j] || graph[i][j];
                }
            }

            // Verify if all nodes are connected
            if (c_size == g_size)
            {
                return true;
            }

            // Verify if there is no edge to expand the incomplete graph
            if (old_size == c_size)
            {
                // Graph is not connex
                return true;
            }
        }
    }

    return true;
}

int main(void)
{
    bool** graph;

    // Initialize the random generator
    srand(time(0));

    graph = new bool*[graphSize];

    for (int i = 0; i < graphSize; ++i) {
        graph[i] = new bool[graphSize];
    }

    // Generate a graph, with a defined density (here it's set to 0.19)
    for (int i = 0; i < graphSize; ++i) {
        for (int j = i; j < graphSize; ++j) {
            if (i == j) {
                graph[i][j] = false;
            } else {
                graph[i][j] = graph[j][i] = (prob() < density);
            }
        }
    }

    // Graphical representation of the graph
    for (int i = 0; i < graphSize; ++i) {
        for (int j = 0; j < graphSize; ++j) {
            cout << static_cast<int> (graph[i][j]) << " ";
        }
        cout << endl;
    }

    int startNode = 1;
 
    while (0)
    {

    }

    // Free the allocated memory
    for (int i = 0; i < graphSize; ++i) {
        delete graph[i];
    }

    delete graph;
}
