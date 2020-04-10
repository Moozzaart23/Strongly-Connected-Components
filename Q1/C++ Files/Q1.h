#ifndef Q1_H_INCLUDED
#define Q1_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

/**
 *@file Q-1.h
 *@author Anish Dey, Anish Walia, Shikhar Dhawale, Aniruddh Gupta
 *@date February 20,2020
 *@brief This is the file containing the definition of the class and its associated functions
*/

/*! \class Graph
    \brief This is a class Graph
    
    This class contains an integer variable about the number of Vertices and an array of Adjacency Lists.
    It is basically used to initialise a graph with its vertices and adjacency list. The class also contains some other member functions
*/
class Graph
{

    int V;          /**<Number of Verices in the Graph*/
    list<int> *adj; /**<An array of Adjacency Lists basically used for Graph representation*/

    /**
     *\brief getFinishingTime() method
    * This function is mainly used to get the finishing time of the vertices when a DFS is implemented on this Graph in the form of stack.
    * The top element of stack has the maximum finishing time
    * @param v is an integer argument
    * @param vis is a boolean array
    * @param s is an integer stack data structure
    *Call this function as follow:
    *@code
    getFinishingTime(vertices,visited,stack)
    *@endcode
    */
    void getFinishingTime(int v, bool vis[], stack<int> &s);

    /**
     *\brief DFS() method
    * This is a recursive function to print DFS starting from v
    * @param v is an integer argument
    * @param vis is a boolean array
    *Call this function as follow:
    *@code
    DFS(vertices,visited)
    *@endcode
    */
    void DFS(int v, bool vis[]);

public:
    int nos = 0;
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
    void addEdge(int u, int v);

    /**
     *\brief findSCCs() method
    * The main function that finds and prints the strongly connected components.
    *Call this function as follow:
    *@code
    findSCCs()
    *@endcode
    */
    void findSCCs();

    /**
     *\brief getReverse() method
    * The function that returns reverse (or transpose) of the graph
    *Call this function as follow:
    *@code
    getReverse()
    *@endcode
    *@return a member of the Graph class 
    */
    Graph getReverse();
};

#endif
