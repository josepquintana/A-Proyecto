#include "Graph.h"

using namespace std;


/**Grandaria de l'espai de coordenades al cas dels 'Random Grafs Geometrics'.*/
#define MAXGRID 200

#define MAXDISTANCE 200

Graph::Graph(int maxId) {
    this->maxId = maxId;
    maxIdActiu = -1;
    minIdActiu = -1;
    nV = 0;
    nA = 0;
    nodeLG n;
    n.actiu = false;
    n.adjacencies = set<int>();
    n.coord.first = -1;
    n.coord.second = -1;
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

int Graph::getNVertexs() { return nV; }

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

void Graph::setRandomCoordinates(int maxX, int maxY){

    srand(time(0));
    for(int i = 0; i < nV; ++i){
        
        int randX = rand();
            //cout << "randX: " << randX <<endl;
        int x = (randX % (maxX + 1));
            nodes[i].coord.first = x;



        
        int randY = rand();
            //cout << "randY: " << randY <<endl;
        int y = (randY % (maxY + 1));
            nodes[i].coord.second = y;

           //cout << "nodo: " << i <<endl;
           // cout << "      x=" << x << ", y=" << y << endl;

    }

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

Graph Graph::generateRGG(int nV){

    srand(time(0));
    int randD = rand();
    int randomDistance = (randD % (MAXDISTANCE + 1));
        
       

    Graph lg = generateActivatedGraph(nV);
    lg.setRandomCoordinates(30, 30);
    for(int i = 0; i < nV; ++i){
        for(int j = i+1; j < nV; ++j){
           int coordxi = lg.nodes[i].coord.first;
           int coordyi = lg.nodes[i].coord.second;

           int coordxj = lg.nodes[j].coord.first;
           int coordyj = lg.nodes[j].coord.second;

            /*
            cout << "en generateRGG, en el bucle interno, coordenadas:" << endl;
            
            cout << "  NODO i:" << endl;
            cout << "      x = " << coordxi << ", y= " << coordyi  << endl;

            cout << "  NODO j:" << endl;
            cout << "      x = " << coordxj << ", y= " << coordyj  << endl;

            int d = 1;*/

            int d = sqrt (pow(coordxj-coordxi, 2) + pow(coordyj-coordyi, 2));


            if(d < randomDistance){
                lg.addAresta(i, j);
            }


        }
    }

    return lg;
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

vector<vector<int> > Graph::getConnectedComponents() {
    vector<vector<int> > components;
    bool *visited = new bool[this->nV];
    for (int u = 0; u < this->nV; ++u) { visited[u] = false; }
    for (int u = 0; u < this->nV; ++u) {
        if (not visited[u]) {
            visited[u] = true;
            int exists = -1;
            for (int k = 0; k < components.size(); k++) {
                for(int h = 0; h < components[k].size(); ++h) {
                    if(h == u) exists = k;
                }
            }
            if (exists < 0) {
                vector<int> cc(1, u);
                components.push_back(cc);
                exists = components.size() - 1;
            }
            for (set<int>::iterator it = this->nodes[u].adjacencies.begin(); it != this->nodes[u].adjacencies.end(); ++it) {
                if(not visited[*it]) {
                    components[exists].push_back(*it);
                }
            }
        }
    }

    return components;
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