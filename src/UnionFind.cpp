#include "UnionFind.h"

using namespace std;

UnionFind::UnionFind(int maxID) {
    nClasses = 0;
    this->maxID = maxID;
    maxActiveID = -1;
    minActiveID = -1;
    UFnode node{};
    node.active = false;
    nodes = vector<UFnode>(maxID + 1, node);
}

void UnionFind::makeSet(int id) {
    if (id > maxID)
        cout << "The ID value '" << id << "' is greater than maxID" << endl;
    else if (hasNode(id))
        cout << "A node with ID '" << id << "' already exists" << endl;
    else {
        ++nClasses;
        if (maxActiveID == -1) {
            maxActiveID = id;
            minActiveID = id;
        }
        else {
            if (id > maxActiveID)
                maxActiveID = id;
            else if (id < minActiveID)
                minActiveID = id;
        }
        nodes[id].active = true;
        nodes[id].parent = id;
        nodes[id].rank = 0;
    }
}

void UnionFind::makeUnion(int id1, int id2) {
    if (not hasNode(id1))
        cout << "A vertex with ID '" << id1 << "' does not exist" << endl;
    else if (not hasNode(id2))
        cout << "A vertex with ID '" << id2 << "' does not exist" << endl;
    else {
        if (id1 != nodes[id1].parent)
            id1 = find(id1);
        if (id2 != nodes[id2].parent)
            id2 = find(id2);
        if (id1 == id2)
            cout << "Vertices '" << id1 << "' and '" << id2 << "' already belong to the same equivalence class" << endl;
        else {
            --nClasses;
            if (nodes[id1].rank > nodes[id2].rank) {
                nodes[id2].parent = id1;
                nodes[id1].rank = max(nodes[id1].rank, nodes[id2].rank + 1);
            }
            else {
                nodes[id1].parent = id2;
                nodes[id2].rank = max(nodes[id2].rank, nodes[id1].rank + 1);
            }
        }
    }
}

int UnionFind::find(int id) {
    if (not hasNode(id)) {
        cout << "A vertex with ID '" << id << "' does not exist" << endl;
        return -1;
    }
    return recFind(id);
}

int UnionFind::recFind(int id) {
    if (id == nodes[id].parent)
        return id;
    nodes[id].parent = recFind(nodes[id].parent);
    return nodes[id].parent;
}

int UnionFind::getNClasses() { return nClasses; }

bool UnionFind::hasNode(int id) {
    if (id > maxID) {
        cout << "The ID value '" << id << "' is greater than maxID." << endl;
        return false;
    }
    return nodes[id].active;
}

bool UnionFind::equivalent(int id1, int id2) {
    if (not hasNode(id1))
        cout << "A vertex with ID '" << id1 << "' does not exist" << endl;
    else if (not hasNode(id2))
        cout << "A vertex with ID '" << id2 << "' does not exist" << endl;
    else {
        if (id1 != nodes[id1].parent)
            id1 = find(id1);
        if (id2 != nodes[id2].parent)
            id2 = find(id2);
        return id1 == id2;
    }
    return false;
}

string UnionFind::toString() {
    vector<vector<int>> classes(maxID + 1, vector<int>(0));
    for (int i = minActiveID; i <= maxActiveID; ++i)
        if (nodes[i].active)
            classes[find(i)].push_back(i);
    string result;
    for (int i = minActiveID; i <= maxActiveID; ++i)
        if (not classes[i].empty()) {
            result += to_string(i) + ":";
            for (int j : classes[i])
                result += to_string(j) + ' ';
            result += '\n';
        }
    return result;
}
