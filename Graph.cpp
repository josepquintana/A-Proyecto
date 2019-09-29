#include "Graph.h"

using namespace std;

Graph::Graph(int maxId) {
    this->maxId = maxId;
    maxIdActiu = -1;
    minIdActiu = -1;
    nV = 0;
    nA = 0;
    nodeLG n;
    n.actiu = false;
    n.adjacencies = set<int>();
    nodes = vector<nodeLG>(maxId + 1, n);
}

bool Graph::isActive(int id) {
    if (id > maxId) {
        cout << "La id " << id << " és més alta que maxId." << endl;
        return false;
    }
    return nodes[id].actiu;
}

void Graph::addAresta(int id1, int id2) {
    if (not isActive(id1))
        cout << "No existeix un vertex amb la id " << id1 << '.' << endl;
    else if (not isActive(id2))
        cout << "No existeix un vertex amb la id " << id2 << '.' << endl;
    else if (adjacent(id1, id2))
        cout << "Els vertexs " << id1 << " i " << id2 << " ja són adjacents." << endl;
    else if (id1 == id2)
        cout << "S'ha donat dos cops la mateixa id." << endl;
    else {
        ++nA;
        nodes[id1].adjacencies.insert(id2);
        nodes[id2].adjacencies.insert(id1);
    }
}

bool Graph::adjacent(int id1, int id2) {
    if (not isActive(id1)) {
        cout << "No existeix un vertex amb la id " << id1 << '.' << endl;
        return false;
    }
    else if (not isActive(id2)) {
        cout << "No existeix un vertex amb la id " << id2 << '.' << endl;
        return false;
    }
    if (nodes[id1].adjacencies.size() < nodes[id2].adjacencies.size())
        return nodes[id1].adjacencies.find(id2) != nodes[id1].adjacencies.end();
    else
        return nodes[id2].adjacencies.find(id1) != nodes[id2].adjacencies.end();
}


Graph Graph::generateActivatedGraph(int nV) {
    Graph lG(nV - 1);
    lG.maxIdActiu = nV - 1;
    lG.minIdActiu = 0;
    lG.nV = nV;
    nodeLG n;
    n.actiu = true;
    n.adjacencies = set<int>();
    lG.nodes = vector<nodeLG>(nV, n);
    return lG;
}


Graph Graph::generateERGraph(int nV, int M) {
    Graph lG = generateActivatedGraph(nV);
    for (int i = 0; i < M; ++i) {
        int id1 = rand() % nV;
        int id2 = rand() % nV;
        if (id1 != id2 and not lG.adjacent(id1, id2))
            lG.addAresta(id1, id2);
        else
            --i;
    }
    return lG;
}

set<int> Graph::getVertexs() {
    set<int> vs = set<int>();
    for (int i = minIdActiu; i <= maxIdActiu; ++i)
        if (isActive(i))
            vs.insert(i);
    return vs;
}

set<pair<int, int> > Graph::getArestes() {
    set<pair<int, int> > arestes = set<pair<int, int> >();
    set<int> vs = getVertexs();
    vector<bool> visited(maxId + 1, false);
    for (set<int>::iterator it1 = vs.begin(); it1 != vs.end(); ++it1) {
        visited[*it1] = true;
        set<int> adjs = getAdjacencies(*it1);
        for (set<int>::iterator it2 = adjs.begin(); it2 != adjs.end(); ++it2)
            if (not visited[*it2]) {
                pair<int, int> aresta;
                aresta.first = *it1;
                aresta.second = *it2;
                arestes.insert(aresta);
            }
    }
    return arestes;
}


set<int> Graph::getAdjacencies(int id) {
    if (not isActive(id)) {
        cout << "No existeix un vertex amb la id " << id << '.' << endl;
        return set<int>();
    }
    return nodes[id].adjacencies;
}

void Graph::recToU(Union &U, vector<bool> &visited, int id) {
    visited[id] = true;
    set<int> adj = getAdjacencies(id);
    for (set<int>::iterator it = adj.begin(); it != adj.end(); ++it)
        if (isActive(*it) and not visited[*it]) {
            U.Union(id, *it);
            recToU(U, visited, *it);
        }
}

Union Graph::toUnion() {
    Union U(maxId);
    for (int i = minIdActiu; i <= maxIdActiu; ++i)
        if (isActive(i)) U.makeSet(i);
    vector<bool> visited(maxId + 1, false);
    for (int i = minIdActiu; i <= maxIdActiu; ++i)
        if (isActive(i) and not visited[i])
            recToU(U, visited, i);
    return U;
}

bool ListGraph::esConnex() {
    if (nV == 0)
        return false;
    if (nA < nV - 1)
        return false;
    return toUnion().getNClasses() == 1;
}

void Graph::print() {
    cout << nV << " Vèrtexs:" << endl;
    if (nV > 0) {
        set<int> vs = getVertexs();
        cout << "    ";
        for (set<int>::iterator it = vs.begin(); it != vs.end(); ++it)
            cout << *it << ' ';
        cout << endl;
    }
    cout << nA << " Arestes:" << endl;
    if (nA > 0) {
        set<pair<int, int> > as = getArestes();
        cout << "    ";
        for (set<pair<int, int>>::iterator it = as.begin(); it != as.end(); ++it)
            cout << '(' << (*it).first << ", " << (*it).second << ") ";
        cout << endl;
    }
}