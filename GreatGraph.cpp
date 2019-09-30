#include "GreatGraph.h"
using namespace std;

vector<int> greatest_components(Graph G){
    vector<vector<int>> components = G.getConnectedComponents();
    int Max = 0;
    for (int i = 0; i < components.size(); i++)
    {
        if(components[i].size() > components[Max].size()){
            Max = i;
        }
    }
    return components[Max];
}

bool is_giant(Graph G, vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
        set<int> adj = G.getAdjacencies(v[i]);
        if(pow(adj.size(),2)-2*adj.size() > 0)
            return true;
        else
            return false;
    }
}

GreatGraph::GreatGraph(){}



void GreatGraph::Test()
{
    std::ofstream file;
    file.open ("dataGG.csv");
    file << "vertex_number,arista_number,p_value,is_giant,greatest_component\n";
    int vertex;
    int test = 20;
    float p = 0;
    int ar = 0;
    srand(time(0));
    for(int k = 0; k< 4; k++){
        vertex = rand()% 200 + 100;
        p = 0;
         for(int j = 0; j < 5; j++){
            for(int i = 0; i< test; i++){
                p = (float)i / (float)20;
                ar = (vertex * (vertex -1) )/2 * p;
                Graph G = Graph::generateERGraph(vertex,ar);
                vector<int> ncomp = greatest_components(G);
                bool giant = is_giant(G,ncomp);
                file <<vertex << "," <<ar << ","<< p << ","<< giant << "," << ncomp.size() << endl;
    }}}
    file.close();
}