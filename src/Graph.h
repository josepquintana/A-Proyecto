/**
 * \file Graph.h
 * \brief Graph class specification
 */

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <ctime>
#include "UnionFind.h"
using namespace std;

/**
 * \brief Stores the information of one Node of the Graph
 */
struct Node {
    bool active; ///< Indicates if the node ID is the same as the vector position of the Graph where this node belongs
    set<int> adjacencies; ///< collection of IDs of the adjacent nodes
    pair<int, int> coordinates; ///< If the node belongs to a RGG stores the coordinates of the node. Otherwise the values will be (-1, -1).
};

/**
 * \class Graph
 * \brief Stores the information of a Grpah and all its nodes using adjacency lists.
 */
class Graph {

private:
    int maxID; ///< Maximum ID value to assign to the Graph nodes
    int maxActiveID; ///< Maximum ID among all the active Graph nodes
    int minActiveID; ///< Minimum ID among all the active Graph nodes
    int n; ///< Total number of vertices
    int m; ///< Total number of edges
    vector<Node> nodes; ///< Vector storing all the nodes, and their properties, belonging to the Graph

    /**
     * \brief Generates a Graph with V vertices and no edges. All the nodes are activated
     * \param n Number of vertices
     * \return Graph(V,0) with n activated vertices and no edges
     */
    static Graph generateActivatedGraph(int n);

public:
    /** Constructors */

    /**
     * \brief Creates and empty Graph.
     * \param maxID Maximum ID value to assign to the Graph nodes
     */
    Graph(int maxID);

    /**
     * \brief Creates a random Graph with a given number of vertices following the Erdős-Rényi model
     * \param n Number of vertices of the generated Graph
     * \param m Number of edges of the resulting Graph
     * \return Random Graph with n vertices generated following the Erdős-Rényi model
     */
    static Graph generateERGraph(int n, int m);

    /**
     * \brief Creates a Random Geometric Graph with a given number of vertices and edges between those vertices that their distance is in the given range 'r'
     * \param n Number of vertices of the generated Graph
     * \param r Neighbour radius parameter
     * \return Random Geometric Graph with n vertices and edges between those vertices that their distance is in the given range 'r'
     */
    static Graph generateRGGraph(int n, float r);

    /**
     * \brief Set all the nodes of the Graph to random coordinates with the specified upper boundary
     * \param maxX Maximum X-axis coordinate
     * \param maxY Maximum Y-axis coordinate
     */
    void setRandomCoordinates(int maxX, int maxY);


    /** Setters */

    /**
     * \brief Adds and edge between the two specified vertices if these exists and an edge does not already exist
     * \param id1 ID of one of the nodes
     * \param id2 ID of the other node
     */
    void addEdge(int id1, int id2);


    /** Getters */

    /**
    * \brief Returns all the vertices of the GraphR
    * \return Vertices IDs of the Graph
    */
    set<int> getVertices();

    /**
    * \brief Returns all the edges of the Graph
    * \return Edges of the Graph
    */
    set<pair<int, int> > getEdges();

    /**
     * \brief Verifies if there's a vertex with the specified ID
     * \param id Vertex ID to check
     * \return True if the Grpah has a vertex with the specified ID. False otherwise
     */
    bool isActive(int id);

    /**
     * \brief Verifies if two vertices are adjacent
     * \param id1 ID of the first vertex
     * \param id2 ID of the second vertex
     * \return True if the two vertices are adjacent. False otherwise
     */
    bool adjacent(int id1, int id2);

    /**
     * \brief Returns the adjacency list of a given vertex
     * \param id Vertex ID to consult its adjacency list
     * \return Adjacency list of vertex 'id'
     */
    set<int> getAdjacencies(int id);

    /**
     * \brief Checks the connectivity of the Graph
     * \return Vertices that make up each of the connected components
     */
    vector<vector<int> > getConnectedComponents();

    /**
    * \brief Returns the number of vertices of the Graph
    * \return Number of vertices of the Graph
    */
    int getNumberVertices();

    /**
     * \brief print via the standard output the Graph
     */
    void print();

};