//
// Created by josep on 2019-09-29.
//

#include "Graph.h"
using namespace std;

Graph::Graph()
{
    this->n = 0;
    adjacencies = new list<int>[0];
}

Graph::Graph(int n)
{
    this->n = n;
    adjacencies = new list<int>[n];
}

void Graph::setNumVertices(int n)
{
    this->n = n;
    adjacencies = new list<int>[n];
}

int Graph::getNumVertices()
{
    return sizeof(adjacencies);
}

bool Graph::existsEdge(int u, int v) {
    for (list<int>::iterator it = adjacencies[u].begin(); it != adjacencies[u].end(); ++it) {
        if(*it == v) return true;
    }
    return false;
}

bool Graph::addEdge(int u, int v)
{
    if(u == v) return false;
    if(this->existsEdge(u, v)) return false;
    adjacencies[u].push_back(v);
    adjacencies[v].push_back(u);
    return true;
}

bool Graph::deleteEdge(int u, int v)
{
    return false;
//    if(u == v) return false;
//    list<int>::iterator it = find(adjacencies[u].begin(), adjacencies[u].end, v);
//    if(it == adjacencies[u].end) return false;
//    adjacencies[u].erase(it);
//    it = find(adjacencies[v].begin(), adjacencies[u].end, u);
//    adjacencies[v].erase(it);
//    return true;
}

int Graph::getNumEdges()
{
    int edges = 0;
    for (int u = 0; u < this->n; ++u) {
        edges += adjacencies[u].size();
    }
    return edges/2;
}

void Graph::DFS(int u, bool visited[], vector<list<int> > components)
{
    visited[u] = true;
    cout << u << " ";
    for (list<int>::iterator it = adjacencies[u].begin(); it != adjacencies[u].end(); ++it) {
        if(not visited[*it]) {
            DFS(*it, visited, components);
        }
    }
}

void Graph::getConnectedComponents()
{
    cout << "\n Connected Components:\n\n";
    vector<list<int> >components;
    bool *visited = new bool[this->n];
    for (int u = 0; u < this->n; ++u) { visited[u] = false; }
    for (int u = 0; u < this->n; ++u) {
        if(not visited[u]) {
            cout << " ";
            DFS(u, visited, components);
            cout << endl;
        }
    }
    cout << endl;
}

void Graph::printGraph()
{
    cout << "\n Graph:\n\n";
    for (int u = 0; u < this->n; ++u) {
        cout << " " << u << "\t| ";
        for (list<int>::iterator it = adjacencies[u].begin(); it != adjacencies[u].end(); ++it) {
            if(it != adjacencies[u].begin()) cout << ", ";
            cout << *it;
        }
        cout << endl;
    }
    cout << endl;
}
