#ifndef Q2_H_INCLUDED
#define Q2_H_INCLUDED
#define ll int64_t

#include <bits/stdc++.h>
using namespace std;
/**
 *@file Q-2.h
 *@author Anish Dey, Anish Walia, Shikhar Dhawale, Aniruddh Gupta
 *@date February 23,2020
 *@brief This is the file containing the definition of the class and its associated functions
*/

/*! \class Graph
    \brief This is a class Graph

    This class contains an integer variable about the number of Vertices and an hash data structure or unordered_map of Adjacency Lists.
    It is basically used to initialise a graph with its vertices and adjacency list. The class also contains some other member functions
*/

class Graph
{
public:
    int v;                           /**<Number of Verices in the Graph*/
    int e;                           /**<Number of edges in the Graph*/
    unordered_map<ll, vector<ll>> g; /**<hash data structure to store the adjacency list*/
    /**
    * A constructor of the Graph class.
    * @param v is an integer argument representing the number of Vertces in the Graph
    * This constructor intialises a member of the Graph Class with the number of vertices and allocates memory to those number of Adjacency Lists
    * This function is called automatically when object of corresponding class is made
    */
    Graph(int V);

    /**
     *\brief addEdge() method
    * This function is mainly used to add a directed edge from vertex u to vertex v
    * @param v is an integer argument
    * @param w is an integer constant
    *Call this function as follow:
    *@code
    addEdge(parent,child)
    *@endcode
    */
    void addEdge(ll x, ll y);

    /**
     *\brief dfs(AdjacencyList G,Vertex V,VistedVertices Ans, VisitedArray Vis) method
    * This is a recursive function to print DFS starting from V
    * @param V is an integer argument
    * @param Vis is a unordered_map data structure
    *Call this function as follow:
    */
    void dfs(unordered_map<ll, vector<ll>> g, ll v, unordered_map<ll, vector<ll>> &ans, unordered_map<ll, ll> &vis);

    /**
     *\brief rev( AdjacencyList G) method
    * The function that returns reverse (or transpose) of the graph
    *Call this function as follow:
    *@code
    rev()
    *@endcode
    *@return hash data structure of the transpose graph
    */
    unordered_map<ll, vector<ll>> rev(unordered_map<ll, vector<ll>> g);

    /**
     *\brief sub(AdjacencyList A,AdjacencyList B) method
    * This function generates a graph which contains vertex which are there in  Graph A but not in Graph B
    *@return Adjacency list of the transpose graph
    */
    unordered_map<ll, vector<ll>> sub(unordered_map<ll, vector<ll>> a, unordered_map<ll, vector<ll>> b);

    /**
     *\brief Union(AdjacencyList A,AdjacencyList B) method
    * This function generates a graph which contains vertex which are there in  Graph A or in Graph B
    *Call this function as follow:
    *@return AdjacencyList of the Union graph
    */
    unordered_map<ll, vector<ll>> Union(unordered_map<ll, vector<ll>> a, unordered_map<ll, vector<ll>> b);

    /**
     *\brief Intersect(AdjacencyList A,AdjacencyList B) method
    * This function generates a graph which contains vertex which are there in  Graph A and in Graph B
    *Call this function as follow:
    *@return AdjacencyList of the Intersection graph
    */
    unordered_map<ll, vector<ll>> intersect(unordered_map<ll, vector<ll>> a, unordered_map<ll, vector<ll>> b);

    /**
     *\brief Desc(AdjacencyList G,vertex V) method
    * This function generates a graph with vertex A and its descendants
    *@return AdjacencyList of the resultant graph
    */
    unordered_map<ll, vector<ll>> Desc(unordered_map<ll, vector<ll>> g, ll v);

    /**
     *\brief DCSC() method
    * This function returns the strongly connected components in the graph
    *@return Prints the vertexes in all the strongly connected components
    */
    void DCSC(unordered_map<ll, vector<ll>> g);
    int DCSCUtil(unordered_map<ll, vector<ll>> g);
};

#endif
