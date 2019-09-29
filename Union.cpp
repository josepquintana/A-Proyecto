#include "Union.h"

using namespace std;

Union::Union(int maxId) {
    nClasses = 0;
    this->maxId = maxId;
    maxIdActiu = -1;
    minIdActiu = -1;
    nodeQU n;
    n.actiu = false;
    nodes = vector<nodeQU>(maxId + 1, n);
}

void Union::makeSet(int id) {
    if (id > maxId)
        cout << "La id " << id << " és més alta que maxId." << endl;
    else if (teNode(id))
        cout << "Ya existeix un node amb la id " << id << '.' << endl;
    else {
        ++nClasses;
        if (maxIdActiu == -1) {
            maxIdActiu = id;
            minIdActiu = id;
        }
        else {
            if (id > maxIdActiu)
                maxIdActiu = id;
            else if (id < minIdActiu)
                minIdActiu = id;
        }
        nodes[id].actiu = true;
        nodes[id].pare = id;
        nodes[id].rank = 0;
    }
}

void Union::Union(int id1, int id2) {
    if (not teNode(id1))
        cout << "No existeix un node amb la id " << id1 << '.' << endl;
    else if (not teNode(id2))
        cout << "No existeix un node amb la id " << id2 << '.' << endl;
    else {
        if (id1 != nodes[id1].pare)
            id1 = find(id1);
        if (id2 != nodes[id2].pare)
            id2 = find(id2);
        if (id1 == id2)
            cout << "Els nodes " << id1 << " i " << id2 << " ya pertanyen a la mateixa classe d'equivalència." << endl;
        else {
            --nClasses;
            if (nodes[id1].rank > nodes[id2].rank) {
                nodes[id2].pare = id1;
                nodes[id1].rank = max(nodes[id1].rank, nodes[id2].rank + 1);
            }
            else {
                nodes[id1].pare = id2;
                nodes[id2].rank = max(nodes[id2].rank, nodes[id1].rank + 1);
            }
        }
    }
}

int Union::find(int id) {
    if (not teNode(id)) {
        cout << "No existeix un node amb la id " << id << '.' << endl;
        return -1;
    }
    return recFind(id);
}

int Union::recFind(int id) {
    if (id == nodes[id].pare)
        return id;
    nodes[id].pare = recFind(nodes[id].pare);
    return nodes[id].pare;
}

int Union::getNClasses() { return nClasses; }

bool Union::teNode(int id) {
    if (id > maxId) {
        cout << "La id " << id << " és més alta que maxId." << endl;
        return false;
    }
    return nodes[id].actiu;
}

bool Union::equivalent(int id1,int id2) {
    if (not teNode(id1))
        cout << "No existeix un node amb la id " << id1 << '.' << endl;
    else if (not teNode(id2))
        cout << "No existeix un node amb la id " << id2 << '.' << endl;
    else {
        if (id1 != nodes[id1].pare)
            id1 = find(id1);
        if (id2 != nodes[id2].pare)
            id2 = find(id2);
        return id1 == id2;
    }
    return false;
}

string Union::toString() {
    vector<vector<int>> classes(maxId + 1, vector<int>(0));
    for (int i = minIdActiu; i <= maxIdActiu; ++i)
        if (nodes[i].actiu)
            classes[find(i)].push_back(i);
    string result = "";
    for (int i = minIdActiu; i <= maxIdActiu; ++i)
        if (not classes[i].empty()) {
            result += to_string(i) + ":";
            for (int j : classes[i])
                result += to_string(j) + ' ';
            result += '\n';
        }
    return result;
}
