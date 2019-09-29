#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <ctime>
#include "Union.h"

using namespace std;

/**Conté la informació d'un possible node del graph.*/
struct nodeLG {
    /**Indica si el Graph té el node amb la id igual a la posició del vector nodes on es troba el node.*/
    bool actiu;
    /**ids dels nodes adjacents al node.*/
    set<int> adjacencies;

    /**coordenades del node en el cas de formar part d'un Random Geometric Graph, en cas contrari els 
    valos seràn iguals a -1.*/
    pair<int, int> coord;
};

/**
 * @class   Graph
 * @brief   Conté la informació d'un Graph implementat amb llistes d'adjacencies.
 */
class Graph {

private:

    int maxId;
    /**id més alta assignable als nodes del Graph.*/
    int maxIdActiu;
    /**id més baixa entre les dels nodes del Graph.*/
    int minIdActiu;
    /**Número de vèrtexs que té el Graph.*/
    int nV;
    /**Número d'arestes que té el Graph.*/
    int nA;
    /**vector que conté els nodes del Graph.*/
    vector<nodeLG> nodes;

    /**
     * Genera un Graph amb n vertexs (tots activats) i cap aresta.
     * @param n Nombre de vèrtexs del Graph.
     * @return  Graph amb n vertexs (tots activats) i cap aresta.
     */
    static Graph generateActivatedGraph(int nV);


public:

    /**Constructores*/

    /**
     * Crea un Graph buit.
     * @param maxId Máxima id assignable a un vèrtex del Graph.
     */
    Graph(int maxId);

    /**
     * Crea un Graph aleatori donat un nombre de vèrtexs seguint el model Erdős-Rényi.
     * @param nV    Nombre de vèrtexs que tindrà el Graph.
     * @param M     Nombre d'arestes del Graph resultant.
     * @return      Graph aleatori amb nV vèrtexs generat segons el model Erdős-Rényi.
     */
    static Graph generateERGraph(int nV, int M);

    static Graph generateRGG(int nV);

    void setRandomCoordinates(int maxX, int maxY);


    /**Modificadores*/

    /**
     * Afegeix una aresta entre els vèrtexs amb les ids donades si aquests existeixen i no existeix ya una entre ells.
     * @param id1   id d'un dels nodes de l'aresta.
     * @param id2   id d'un dels nodes de l'aresta.
     */
    void addAresta(int id1, int id2);


    /**Consultores*/

       /**
     * Retorna la llista d'adjacencies d'un vèrtex amb la id indicada si aquest existeix.
     * @param id    id del vèrtex del que es vol obtenir la llista d'adjacencies.
     * @return      llista d'adjacencies del vètex amb la id donada.
     */
    set<int> getAdjacencies(int id);

     /**
     * Retorna totes les arestes del Graph.
     * @return  arestes del Graph.
     */
    set<pair<int, int> > getArestes();

     /**
     * Retorna totes les ids dels vertexs del Graph.
     * @return  ids dels vertexs del Graph.
     */
    set<int> getVertexs();

    /**
     * Indica si el Graph té un vèrtex amb la id indicada
     * @param id    id del vèrtex que es vol comprovar.
     * @return      true si el Graph té el vèrtex, false altrament.
     */
    bool isActive(int id);

    /**
     * Indica si 2 vèrtexs existents són adjacents.
     * @param id1   id del 1r vèrtex.
     * @param id2   id del 2n vèrtex.
     * @return      true si els vètexs són adjacents, false altrament.
     */
    bool adjacent(int id1, int id2);

      /**
     * Indica quants vèrtexs té el ListGraph.
     * @return  Número de vèrtexs que té el ListGraph.
     */
    int getNVertexs();

    int distance(int x1, int y1, int x2, int y2);

    /**
     * Comprova la connectivitat del Graph
     * @return els vertexs que formen part de cada component
     */
    vector<vector<int> > getConnectedComponents();

    /**Fa cout del graf.*/
    void print();

};
