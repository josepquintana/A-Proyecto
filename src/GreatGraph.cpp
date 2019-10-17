#include "GreatGraph.h"
#include "Graph.h"
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

bool is_giant(Graph G, const vector<int>& v){
    for (int i : v)
    {
        set<int> adj = G.getAdjacencies(i);
        return pow(adj.size(), 2) - 2 * adj.size() > 0;
    }
}

GreatGraph::GreatGraph(){}

void GreatGraph::Test()
{
    std::ofstream file;
<<<<<<< HEAD:src/GreatGraph.cpp
    file.open ("../data/dataGG.csv");
    file << "vertex_number,arista_number,p_value,is_giant,greatest_component\n";
=======
    file.open ("dataGG.csv");
    file << "vertex_number,arista_number,p_value,is_giant,greatest_component,computation_time\n";
>>>>>>> development-jordi:GreatGraph.cpp
    int vertex;
    int test = 20;
    float p = 0;
    int ar = 0;
    clock_t t;
    srand(time(0));
    for(int k = 0; k< 10; k++){
        cout << ".";
        vertex = rand()% 100 + 100;
        p = 0;
         for(int j = 0; j < 5; j++){
            for(int i = 0; i< test; i++){
                p = (float)i / (float)20;
                ar = (vertex * (vertex -1) )/2 * p;
                Graph G = Graph::generateERGraph(vertex,ar);
                t = clock();
                vector<int> ncomp = greatest_components(G);
                t = clock() - t;
                bool giant = is_giant(G,ncomp);
                float time = ((float)t)/CLOCKS_PER_SEC;
                file <<vertex << "," <<ar << ","<< p << ","<< giant << "," << ncomp.size() << "," << time <<endl;
    }}}
    cout << endl;
    file.close();
}