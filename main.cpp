//
// Created by josep on 2019-09-27.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include "Graph.h"
using namespace std;

int selectWorkingMode()
{
    cout << "\n [MODE] Check graph property:\n";
    cout << "\t 1. Connected components\n";
    cout << "\t 0. Exit\n";
    int option;
    cout << "\n > ";
    cin >> option;
    return option;
}

pair<int, int> parseAdjacencies(string line)
{
    stringstream ss(line);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstr(begin, end);
    pair<int, int> vertices;
    vertices = make_pair(stoi(vstr[0]), stoi(vstr[1]));
    return vertices;
}

void createGraph(Graph &G, ifstream &file)
{
    string line;
    getline(file, line); // Graph
    cout << "\nCreating Graph from input file.\n";
    getline(file, line);
    int n = stoi(line);
    G.setNumVertices(n);
    cout << "Graph has " << n << " vertices.\n";
    while(getline(file, line) and line != "EOF") {
        pair<int, int> edge = parseAdjacencies(line);
        if(G.addEdge(edge.first, edge.second)) cout << "Edge between " << edge.first << "\t and " << edge.second << "\t has been added.\n";
        else cout << "Not adding edge between " << edge.first << " and " << edge.second << ".\n";
    }
    // Graph G is now constructed
}

void checkConnectivity(Graph &G)
{
    G.getConnectedComponents();
}

int main(int argc, char* argv[])
{
    ifstream file;
    if(argc != 2) { cout << "\nNo graph file has been specified.\n"; return 1; }
    file.open(argv[1]);
    if(not file.good()) { cout << "\nUnable to open the specified graph file.\n"; return 1; }

    Graph G;
    createGraph(G, file);
    file.close();

    G.printGraph();

    int mode = selectWorkingMode();
    while (mode != 0) {
        switch (mode) {
            case 1:
                checkConnectivity(G);
                break;
            default:
                cout << "\n Invalid option!\n";
                break;
        }
        mode = selectWorkingMode();
    }

    return 0;
}