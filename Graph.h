//
// Created by josep on 2019-09-27.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

#ifndef A_PROYECTO_GRAPH_H
#define A_PROYECTO_GRAPH_H

class Graph
{

private:
    int n;
    list<int> *adjacencies;

protected:
    void DFS(int u, bool visited[], vector<list<int> > components);

public:
    Graph();
    Graph(int n);

    void setNumVertices(int n);
    int getNumVertices();
    bool existsEdge(int u, int v);
    bool addEdge(int u, int v);
    bool deleteEdge(int u, int v);
    int getNumEdges();

    void getConnectedComponents();

    void printGraph();
};

#endif //A_PROYECTO_GRAPH_H
