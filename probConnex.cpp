#include "probConnex.h"
using namespace std;

probConnex::probConnex(){}

void probConnex::Experiment()
{
    std::ofstream file;
    file.open ("dataERG.csv");
    file << "vertex_number,arista_number,p_value,és_connex,n_connexions,\n";
    int vertex;
    cin >> vertex;
    int test = 102;
    float p = 0;
    int ar = 0;
    for(int i = 1; i< test; i++){
        ar = (vertex * (vertex -1) )/2 * p;
        Graph G = Graph::generateERGraph(vertex,ar);
        bool esConnex = G.esConnex();
        int connexions = G.getConnectedComponents().size();
        file <<vertex << "," <<ar << ","<< p << ","<< connex << "," << connexions << endl;
        p = (float)i / (float)100;
    }
    file.close();

    std::ofstream file;
    file.open ("dataRRG.csv");
    file << "vertex_number,arista_number,p_value,és_connex,n_connexions,\n";
    int vertex;
    cin >> vertex;
    int test = 102;
    float p = 0;
    int ar = 0;
    for(int i = 1; i< test; i++){
        ar = (vertex * (vertex -1) )/2 * p;
        Graph G = Graph::generateRGG(vertex,ar);
        bool connex = G.esConnex();
        int connexions = G.getConnectedComponents().size();
        file <<vertex << "," <<ar << ","<< p << ","<< connex << "," << connexions << endl;
        p = (float)i / (float)100;
    }
    file.close();
}