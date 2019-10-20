/**
 * \file UnionFind.h
 * \brief UnionFind class specification
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * \brief Stores the information of one Node of Union-Find disjoint set
 */
struct UFnode {
    bool active; ///< Indicates if the node ID is the same as the vector position of the Graph where this node belongs
    int parent; ///< Stores the ID of the node's parent
    int rank; ///< Rank associated with this node
};

/**
 * \class UnionFind
 * \brief Stores the information of a Union-Find disjoint set and its related information.
 */
class UnionFind
{
private:
    int nClasses; ///< Number of different equivalence classes of the UnionFind set
    int maxID; ///< Maximum ID value to assign to the UnionFind set
    int maxActiveID; ///< Maximum ID among all the active UnionFind set nodes
    int minActiveID; ///< Minimum ID among all the active UnionFind set nodes
    vector<UFnode> nodes; ///< Vector storing all the nodes, and their properties, belonging to the UnionFind set

    /**
     * \brief Return the equivalence class representative vertex ID of the given node
     * \param id Vertex ID to check its equivalence class representative
     * \return Vertex ID of the representative node of the given node's equivalence class
     */
    int recFind(int id);

public:

    /** Constructors */

    /**
     * \brief UnionFind class constructor
     * \param maxId Maximum vertex ID a node of the UnionFind set can have
     */
    explicit UnionFind(int maxId);


    /** Setters */

    /**
     * \brief Create an equivalence class with its representative being the given vertex ID
     * \param id Vertex ID of the representative of the newly created equivalence class
     */
    void makeSet(int id);

    /**
     * \brief Merges the equivalence classes of the nodes with the given IDs if they exists and are from different classes
     * \param id1 Vertex ID of the first UnionFind node
     * \param id2 Vertex ID of the first UnionFind node
     */
    void makeUnion(int id1, int id2);

    /** Getters */

    /**
     * \brief Transforms the UnionFind into a string.
     * \return string with the UnionFind content
     */
    string toString();

    /**
     * \brief Get the vertex ID of the representative node of the equivalence class of the given node
     * \param id Vertex ID to find the representative of its equivalence class
     * \return ID of the representative node of the equivalence class from the UnionFind node with the given id
     */
    int find(int id);

    /**
     * \brief Get the number of different equivalence classes of the UnionFind set
     * \return Number of different equivalence classes of the UnionFind set
     */
    int getNClasses();

    /**
     * \brief Checks if the UnionFind set has a node with the given ID
     * \param id Vertex ID to check
     * \return True if the UnionFind set has a node with ID 'id'. Otherwise, false
     */
    bool hasNode(int id);

    /**
     * \brief Check if two nodes belong to the same equivalence class.
     * \param id1 ID of one of the nodes
     * \param id2 ID of the other node
     * \return True if the two given nodes belong two the same equivalence class. Otherwise, or if any of the IDs does not exists, false
     */
    bool equivalent(int id1,int id2);

};


