#include "GreatGraph.h"
using namespace std;

void greatest_components(Graph G, int maxVertex){
    Find f(maxVertex);
    set<int> V = G.getVertexs();
    for (int i = 0; i < V.size(); i++)
    {
        f.makeSet(*V.find(i));
        set<int> adj = G.getAdjacencies(*V.find(i));
        for (int j = 0; j < adj.size(); j++)
        {
            if(f.equivalent(*V.find(i),*adj.find(j))){
                f.makeUnion(*V.find(i),*adj.find(j));
            }
        }
    }
}

GreatGraph::GreatGraph(){}

void GreatGraph::Test()
{
    std::ofstream file;
    file.open ("data.csv");
    file << "vertex_number,arista_number,p_value,greatest_component\n";
    int vertex;
    cin >> vertex ;
    int test = 102;
    float p = 0;
    int ar = 0;
    for(int i = 1; i< test; i++){
        ar = (vertex * (vertex -1) )/2 * p;
        Graph G = Graph::generateERGraph(vertex,ar);
        greatest_components(G,vertex-1);
        file <<vertex << "," <<ar << ","<< p << ","<<0 << endl;
        p = (float)i / (float)100;
    }
    file.close();
}