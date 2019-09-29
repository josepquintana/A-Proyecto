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

vector<int> greatest_components(graph G){
    components result;
    vector<bool> visited(G.adj.size(), false);

    for (int i = 0; i < G.V; i++)
    {

        if(!visited[i]){
            visited[i] = true;
            int exist = -1;
            for (int k = 0; k < result.comp.size(); k++)
            {
                if(contains(result.comp[k],i)){
                    exist = k;
                }
            }
            if( exist < 0){
                vector<int> new_comp(1,i);
                result.comp.push_back(new_comp);
                exist = result.comp.size()-1;
            }
            for (int j = 0; j < G.adj[i].size(); j++)
            {
                if(!visited[G.adj[i][j]]){
                    result.comp[exist].push_back(G.adj[i][j]);
                }
            }
        }
    }
    int Max = 0;
    for (int i = 1; i < result.comp.size(); i++)
    {
        if(result.comp[Max].size() < result.comp[i].size()){
            Max = i;
        }
    }

    return result.comp[Max];
}


int main(int argc, char *argv[])
{
    graph G;
    G.addNode(8);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(0,3);
    G.addEdge(4,5);
    G.addEdge(5,6);
    G.addEdge(6,7);
    G.addEdge(7,4);
    G.addEdge(4,3);
    for (int i = 0; i < G.V; i++)
    {
        cout << i << ':';
        for (int j = 0; j < G.adj[i].size(); j++)
        {
            cout << G.adj[i][j] << ' ';
        }
        cout << endl;
    }
    vector<int> greatest = greatest_components(G);
    for (int i = 0; i < greatest.size(); i++)
    {
        cout << greatest[i] << ' ';
    }
    cout << endl;
    return 0;
}