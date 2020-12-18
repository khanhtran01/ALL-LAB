#include <iostream>
#include <list>
using namespace std;

class DirectedGraph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool *rs);

public:
    DirectedGraph()
    {
        V = 0;
        adj = NULL;
    }
    DirectedGraph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    bool isCyclicRecur(int v, bool visited[], bool recStack[])
    {
        if (visited[v] == false)
        {
            visited[v] = true;
            recStack[v] = true;

            list<int>::iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                if (!visited[*i] && isCyclicRecur(*i, visited, recStack))
                    return true;
                else if (recStack[*i])
                    return true;
            }
        }
        recStack[v] = false; // remove the vertex from recursion stack
        return false;
    }
    bool isCyclic()
    {
        bool *visited = new bool[V];
        bool *stackRecur = new bool[V];
        for (int i = 0 ; i < V ; i++)
        {
            visited[i] = false;
            stackRecur[i] = false;
        }
        return isCyclicRecur(0,visited,stackRecur);
        // Student answer
    }
};
int main()
{
    DirectedGraph g(8);
    int edege[][2] = {{0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4}, {5, 1}, {7, 0}, {7, 1}};

    for (int i = 0; i < 9; i++)
        g.addEdge(edege[i][0], edege[i][1]);

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
}