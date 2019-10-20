#include "Graph.h"
using namespace std;

#define MAXGRID 200 // Random Geometric Graph max coordinate space
#define MAXDISTANCE 200

Graph::Graph(int maxID) {
    this->maxID = maxID;
    maxActiveID = -1;
    minActiveID = -1;
    this->n = 0;
    this->m = 0;
    Node node;
    node.active = false;
    node.adjacencies = set<int>();
    node.coordinates.first = -1;
    node.coordinates.second = -1;
    this->nodes = vector<Node>(maxID + 1, node);
}

Graph Graph::generateActivatedGraph(int n) {
    Graph G(n - 1);
    G.maxActiveID = n - 1;
    G.minActiveID = 0;
    G.n = n;
    Node node;
    node.active = true;
    node.adjacencies = set<int>();
    G.nodes = vector<Node>(n, node);
    return G;
}

Graph Graph::generateERGraph(int n, int m) {
    Graph G = generateActivatedGraph(n);
    for (int i = 0; i < m; ++i) {
        int id1 = rand() % n;
        int id2 = rand() % n;
        if (id1 != id2 and not G.adjacent(id1, id2))
            G.addEdge(id1, id2);
        else
            --i;
    }
    return G;
}

Graph Graph::generateRGGraph(int n, float r){

    srand(time(0));
    int randD = rand();
    int randomDistance = (int) 1/r;

    Graph G = generateActivatedGraph(n);
    G.setRandomCoordinates(30, 30);
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            int coordxi = G.nodes[i].coordinates.first;
            int coordyi = G.nodes[i].coordinates.second;

            int coordxj = G.nodes[j].coordinates.first;
            int coordyj = G.nodes[j].coordinates.second;

            /*
            cout << "en generateRGG, en el bucle interno, coordenadas:" << endl;

            cout << "  NODO i:" << endl;
            cout << "      x = " << coordxi << ", y= " << coordyi  << endl;
            cout << "  NODO j:" << endl;
            cout << "      x = " << coordxj << ", y= " << coordyj  << endl;
            int d = 1;
             */

            int d = sqrt (pow(coordxj-coordxi, 2) + pow(coordyj-coordyi, 2));

            if(d < randomDistance){
                G.addEdge(i, j);
            }
        }
    }

    return G;
}

void Graph::setRandomCoordinates(int maxX, int maxY){

    srand(time(0));
    for(int i = 0; i < n; ++i) {
        int randX = rand();
        //cout << "randX: " << randX <<endl;
        int x = (randX % (maxX + 1));
        nodes[i].coordinates.first = x;

        int randY = rand();
        //cout << "randY: " << randY <<endl;
        int y = (randY % (maxY + 1));
        nodes[i].coordinates.second = y;

        //cout << "nodo: " << i <<endl;
        // cout << "      x=" << x << ", y=" << y << endl;
    }
}

bool contains(int n, vector<int> V){
    for (int i = 0; i < V.size(); i++) {
        if(V[i] == n)
            return true;
    }
    return false;
}

void Graph::addEdge(int id1, int id2) {
    if (not isActive(id1))
        cout << "A vertex with ID '" << id1 << "' does not exist" << endl;
    else if (not isActive(id2))
        cout << "A vertex with ID '" << id2 << "' does not exist" << endl;
    else if (adjacent(id1, id2))
        cout << "The vertices '" << id1 << "' and '" << id2 << "' are already adjacent." << endl;
    else if (id1 == id2)
        cout << "The two given IDs are the same." << endl;
    else {
        ++m;
        nodes[id1].adjacencies.insert(id2);
        nodes[id2].adjacencies.insert(id1);
    }
}

set<int> Graph::getVertices() {
    set<int> vs = set<int>();
    for (int i = minActiveID; i <= maxActiveID; ++i) {
        if (isActive(i)) {
            vs.insert(i);
        }
    }
    return vs;
}

set<pair<int, int> > Graph::getEdges() {
    set<pair<int, int> > edges = set<pair<int, int> >();
    set<int> vs = getVertices();
    vector<bool> visited(maxID + 1, false);
    for (set<int>::iterator it1 = vs.begin(); it1 != vs.end(); ++it1) {
        visited[*it1] = true;
        set<int> adjs = getAdjacencies(*it1);
        for (set<int>::iterator it2 = adjs.begin(); it2 != adjs.end(); ++it2)
            if (not visited[*it2]) {
                pair<int, int> aresta;
                aresta.first = *it1;
                aresta.second = *it2;
                edges.insert(aresta);
            }
    }
    return edges;
}

bool Graph::isActive(int id) {
    if (id > maxID) {
        cout << "The ID value '" << id << "' is greater than maxID." << endl;
        return false;
    }
    return nodes[id].active;
}

bool Graph::adjacent(int id1, int id2) {
    if (not isActive(id1)) {
        cout << "A vertex with ID '" << id1 << "' does not exist" << endl;
        return false;
    }
    else if (not isActive(id2)) {
        cout << "A vertex with ID '" << id2 << "' does not exist" << endl;
        return false;
    }
    if (nodes[id1].adjacencies.size() < nodes[id2].adjacencies.size())
        return nodes[id1].adjacencies.find(id2) != nodes[id1].adjacencies.end();
    else
        return nodes[id2].adjacencies.find(id1) != nodes[id2].adjacencies.end();
}

set<int> Graph::getAdjacencies(int id) {
    if (not isActive(id)) {
        cout << "A vertex with ID '" << id << "' does not exist" << endl;
        return set<int>();
    }
    return nodes[id].adjacencies;
}

vector<vector<int> > Graph::getConnectedComponents() {
    vector<vector<int> > components;
    bool *visited = new bool[this->n];
    for (int u = 0; u < this->n; ++u) { visited[u] = false; }
    for (int u = 0; u < this->n; ++u) {
        if (not visited[u]) {
            visited[u] = true;
            int exists = -1;
            for (int k = 0; k < components.size(); k++) {
                for(int h = 0; h < components[k].size(); ++h) {
                    if(components[k][h] == u) exists = k;
                }
            }
            if (exists < 0) {
                vector<int> cc(1, u);
                components.push_back(cc);
                exists = components.size() - 1;
            }
            for (set<int>::iterator it = this->nodes[u].adjacencies.begin(); it != this->nodes[u].adjacencies.end(); ++it) {
                if(not visited[*it] && !contains(*it,components[exists])) {
                    components[exists].push_back(*it);
                }
            }
        }
    }

    return components;
}

int Graph::getNumberVertices() { return n; }

void Graph::print() {
    cout << n << " Vertices:" << endl;
    if (n > 0) {
        set<int> vs = getVertices();
        cout << "    ";
        for (set<int>::iterator it = vs.begin(); it != vs.end(); ++it)
            cout << *it << ' ';
        cout << endl;
    }
    cout << m << " Edges:" << endl;
    if (m > 0) {
        set<pair<int, int> > as = getEdges();
        cout << "    ";
        for (set<pair<int, int>>::iterator it = as.begin(); it != as.end(); ++it)
            cout << '(' << (*it).first << ", " << (*it).second << ") ";
        cout << endl;
    }
}