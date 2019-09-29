#include <vector>
#include <iostream>
using namespace std;

struct graph{
int V = 0;
vector<vector<int>> adj;
    public:
        void addEdge(int i, int v){
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
        void addNode(int n){
            V += n;
            for (int i = 0; i < n; i++)
            {
                vector<int> new_node;
                adj.push_back(new_node);
            }
        }
};

struct components
{
    /* data */
    vector<vector<int>> comp;
};
bool contains(vector<int> v,int index){
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] == index){
            return true;
        }
    }
    return false;
}

components greatest_components(graph G){
    components result;
    vector<bool> visited(G.V, false);
    for (int i = 0; i < G.V; i++)
    {
        /* code */
        if(!visited[i]){
            visited[i] = true;
            vector<int> new_comp(1,i);
            result.comp.push_back(new_comp);
            for (int j = 0; j < G.adj[i].size(); j++)
            {
        /* code */
            if(!visited[j])
                visited[j] = true;
                result.comp[i].push_back(j);
            }
        }
        else{
            for (int j = 0; j < G.adj[i].size(); j++)
            {
                if(!visited[j]){
                    int container = -1;
                    for (int k = 0; k < result.comp.size(); k++)
                    {
                        if(contains(result.comp[k],j)){
                            container = k;
                        }
                    }
                    visited[j] = true;
                    result.comp[container].push_back(j);
                }
            }
        }
    }
    return result;
}


int main(int argc, char const *argv[])
{
    graph G;
    G.addNode(5);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(3,4);
    for (int i = 0; i < G.V; i++)
    {
        cout << i << ':';
        for (int j = 0; j < G.adj[i].size(); j++)
        {
            cout << G.adj[i][j] << ' ';
        }
        cout << endl;

    }
    return 0;
}


