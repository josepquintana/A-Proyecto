#include "probConnex.h"
using namespace std;

probConnex::probConnex(){}

void probConnex::Experiment()
{
    std::ofstream file;
    file.open ("dataERG.csv");
    file << "vertex_number,arista_number,p_value,és_connex,n_connexions,\n";
    int vertex;
    int test = 20;
    float p = 0;
    int ar = 0;
    srand(time(0));
    for(int k = 0; k< 4; k++){
        vertex = rand()% 100 + 10;
        p = 0;
         for(int j = 0; j < 5; j++){
    for(int i = 0; i< test; i++){
        p = (float)i / (float)20;
        ar = (vertex * (vertex -1) )/2 * p;
        Graph G = Graph::generateERGraph(vertex,ar);
        bool connex = G.getConnectedComponents().size()<2;
        int connexions = G.getConnectedComponents().size();
        file <<vertex << "," <<ar << ","<< p << ","<< connex << "," << connexions << endl;
    }}}
    file.close();

    file.open ("dataRRG.csv");
    file << "vertex_number,arista_number,r_value,és_connex,n_connexions,\n";

    for(int k = 0; k< 4; k++){
        vertex = rand()% 100 + 10;
        p = 0;
         for(int j = 0; j < 5; j++){
    for(int i = 0; i< test; i++){
        p = (float)i / (float)20;
        Graph G = Graph::generateRGG(vertex,p);
        bool connex = G.getConnectedComponents().size()<2;
        int connexions = G.getConnectedComponents().size();
        file <<vertex << "," <<G.getArestes().size() << ","<< p << ","<< connex << "," << connexions << endl;
    }}
    }
    file.close();
}