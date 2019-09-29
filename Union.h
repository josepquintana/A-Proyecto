/**
 * @file    Union.h
 * @brief   Especificació de la classe Union.
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**nodeQU del UnionFind set.*/
struct nodeQU {
    /**Indica si el UnionFind set té el node amb la id igual a la posició del vector nodes on es troba el node.*/
    bool actiu;
    /**Indica la id del pare del node.*/
    int pare;
    /**rank associat al node.*/
    int rank;
};

/**
 * @class   Union
 * @brief   Conté la informació d'un UnionFind set amb implementació Union.
 */
class Union {

private:

    /**Nombre de classes d'equivalència diferents al UnionFind set.*/
    int nClasses;
    /**id més alta assignable als nodes del UnionFind set.*/
    int maxId;
    /**id més alta entre les dels nodes del UnionFind set.*/
    int maxIdActiu;
    /**id més baixa entre les dels nodes del UnionFind set.*/
    int minIdActiu;
    /**vector que conté els nodes del UnionFind set.*/
    vector<nodeQU> nodes;

    /**
     * Retorna la id del node representant de la classe d'equivalència del node donat existent.
     * @param id    id del node del que es vol saber el representant de la classe d'equivalència a la que pertany.
     * @return      id del node representant de la classe d'equivalència del UFNode del que s'ha donat la id.
     */
    int recFind(int id);

public:

    /**Constructoras*/

    /**
     * Constructora de la classe Union.
     * @param maxId id més alta que pot tenir un node de l'UnionFind set.
     */
    Union(int maxId);

    /**Modificadoras*/

    /**
     * Crea una nova classe d'equivalència amb un node representant amb la id donada si no existeix cap node amb
     * aquesta id.
     * @param id    id del node representant de la nova classe d'equivalència.
     */
    void makeSet(int id);

    /**
     * Uneix les classes d'equivalència dels nodes amb ids: id1 i id2 si els nodes existeixen i són de classes diferents.
     * @param id1   id del 1r UFNode.
     * @param id2   id del 2n UFNode.
     */
    void makeUnion(int id1, int id2);

    /**Consultoras*/

    /**
     * Convierte Union a string.
     * @return  string con el contenido de Union.
     */
    string toString();

    /**
     * Retorna la id del node representant de la classe d'equivalència del node donat si aquest node existeix, -1 altrament.
     * @param id    id del node del que es vol saber el representant de la classe d'equivalència a la que pertany.
     * @return      id del node representant de la classe d'equivalència del UFNode del que s'ha donat la id.
     */
    int find(int id);

    /**
     * Retorna el nombre de classes d'equivalència diferents que té el UnionFind set.
     * @return  nombre de classes d'equivalència diferents que té el UnionFind set.
     */
    int getNClasses();

    /**
     * Retorna si el UnionFind set té un node amb la id donada.
     * @param id    id que es vol comprovar si pertany a algun UFNode del UnionFind set.
     * @return      true si el UnionFind set té un UFNode amb la id donada, false altrament.
     */
    bool teNode(int id);

    /**
     * Retorna si els nodes amb les ids donades (si els dos existeixen) pertanyen a la mateixa classe d'equivalència.
     * @param id1   id del 1r node.
     * @param id2   id del 2n node.
     * @return      true si els nodes amb les ids donades pertanyen a la mateixa classe d'equivalència, false en cas
     *              contrari o si alguna de les id no pertany a cap node del UnionFind set.
     */
    bool equivalent(int id1,int id2);

};


