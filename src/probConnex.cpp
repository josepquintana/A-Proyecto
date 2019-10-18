#include "probConnex.h"
#include "Graph.h"
using namespace std;

probConnex::probConnex(){}

void probConnex::Experiment()
{
    std::ofstream file;
    file.open ("../data/dataERG.csv");
    file << "vertex_number,arista_number,p_value,és_connex,n_connexions,computation_time\n";
    int vertex;
    int test = 20;
    float p = 0;
    int ar = 0;
    clock_t t;
    srand(time(0));
    for(int k = 0; k< 4; k++){
        cout << ".";
        vertex = rand()% 100 + 10;
        p = 0;
         for(int j = 0; j < 5; j++){
    for(int i = 0; i< test; i++){
        p = (float)i / (float)20;
        ar = (vertex * (vertex -1) )/2 * p;
        Graph G = Graph::generateERGraph(vertex,ar);
        bool connex = G.getConnectedComponents().size()<2;
        t = clock();
        int connexions = G.getConnectedComponents().size();
        t = t -clock();
        float time = ((float)t)/CLOCKS_PER_SEC;
        file <<vertex << "," <<ar << ","<< p << ","<< connex << "," << connexions << "," << time << endl;
    }}}
    cout << endl;
    file.close();

    file.open ("../data/dataRRG.csv");
    file << "vertex_number,arista_number,r_value,és_connex,n_connexions,computation_time\n";

    for(int k = 0; k< 4; k++){
        cout << ".";
        vertex = rand()% 100 + 10;
        p = 0;
         for(int j = 0; j < 5; j++){
    for(int i = 0; i< test; i++){
        p = (float)i / (float)20;
        Graph G = Graph::generateRGG(vertex,p);
        bool connex = G.getConnectedComponents().size()<2;
        t = clock();
        int connexions = G.getConnectedComponents().size();
        t = t -clock();
        float time = ((float)t)/CLOCKS_PER_SEC;
        file <<vertex << "," <<G.getArestes().size() << ","<< p << ","<< connex << "," << connexions << "," << time << endl;
    }}
    }
    cout << endl;
    file.close();
}