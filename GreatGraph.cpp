#include "GreatGraph.h"
using namespace std;


/* bool contains(vector<int> v,int index){
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] == index){
            return true;
        }
    }
    return false;
} */

/* vector<int> greatest_components(Graph G){
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
} */

GreatGraph::GreatGraph(){}

void GreatGraph::Test()
{
    int vertex;
    cin >> vertex ;
    int test = 100;
    float p = 0;
    int ar = 0;
    printf ("vertex_number\tarista_number\tp_value\tgreatest_component\n");
    for(int i = 1; i< test; i++){
        ar = (vertex * (vertex -1) ) * p;
        Graph G = Graph::generateERGraph(vertex,ar);
        printf ("%d\t%d\t%f\t%d\n", vertex,ar,p,0);
        p = (float)i / (float)100;
    }
}