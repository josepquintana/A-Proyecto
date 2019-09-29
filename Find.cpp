#include "Find.h"

using namespace std;

Find::Find(int maxId) {
    nClasses = 0;
    this->maxId = maxId;
    maxIdActiu = -1;
    minIdActiu = -1;
    nodeQF n;
    n.actiu = false;
    nodes = vector<nodeQF>(maxId + 1, n);
}

void Find::makeSet(int id) {
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
        nodes[id].classe = id;
    }
}

void Find::Union(int id1, int id2) {
    if (not teNode(id1))
        cout << "No existeix un node amb la id " << id1 << '.' << endl;
    else if (not teNode(id2))
        cout << "No existeix un node amb la id " << id2 << '.' << endl;
    else {
        int classe1 = nodes[id1].classe;
        int classe2 = nodes[id2].classe;
        if (classe1 == classe2)
            cout << "Els nodes " << id1 << " i " << id2 << " ya pertanyen a la mateixa classe d'equivalència." << endl;
        else {
            --nClasses;
            for (int i = minIdActiu; i <= maxIdActiu; ++i)
                if (nodes[i].classe == classe1)
                    nodes[i].classe = classe2;
        }
    }
}

int Find::find(int id) { return nodes[id].classe; }

int Find::getNClasses() { return nClasses; }

bool Find::teNode(int id) {
    if (id > maxId) {
        cout << "La id " << id << " és més alta que maxId." << endl;
        return false;
    }
    return nodes[id].actiu;
}

bool Find::equivalent(int id1,int id2) {
    if (not teNode(id1))
        cout << "No existeix un node amb la id " << id1 << '.' << endl;
    else if (not teNode(id2))
        cout << "No existeix un node amb la id " << id2 << '.' << endl;
    else {
        return nodes[id1].classe == nodes[id2].classe;
    }
    return false;
}

string Find::toString() {
    vector<vector<int>> classes(maxId + 1, vector<int>(0));
    for (int i = minIdActiu; i <= maxIdActiu; ++i)
        if (nodes[i].actiu)
            classes[nodes[i].classe].push_back(i);
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