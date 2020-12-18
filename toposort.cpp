#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
    list<int> adjList;
    int size;

public:
    Adjacency() {}
    Adjacency(int V) {}
    void push(int data)
    {
        adjList.push_back(data);
        size++;
    }
    void print()
    {
        for (auto const &i : adjList)
            cout << " -> " << i;
    }
    void printArray()
    {
        for (auto const &i : adjList)
            cout << i << " ";
    }
    int getSize() { return adjList.size(); }
    int getElement(int idx)
    {
        auto it = adjList.begin();
        advance(it, idx);
        return *it;
    }
};
class Graph
{
    int V;
    Adjacency *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push(w);
    }

    //Heling functions

    void topoSortingRecur(bool visited[], int v, list<int> & stack)
    {
        if (visited[v] == true ) return;
        visited[v] = true;
        for ( int i = 0 ; i < adj[v].getSize() ; i++)
        {
            if (visited[adj[v].getElement(i)] == false)
                topoSortingRecur(visited,adj[v].getElement(i),stack);
        }
        stack.push_back(v);
    }

    void topologicalSort()
    {
        //TODO
        bool * visited = new bool [this->V];
        for ( int i = 0 ; i < this->V ; i++)
            visited[i] = false;
        list<int> stack;
        for ( int i = 0 ; i < this->V ; i++)
        {
            topoSortingRecur(visited,i,stack);
        }
        while(!stack.empty())
        {
            cout<< stack.back() << " ";
            stack.pop_back();
        }
    }
};
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    
    g.topologicalSort();
}