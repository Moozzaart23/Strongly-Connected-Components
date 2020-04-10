#include <bits/stdc++.h>
using namespace std;
#include "Q1.h"

/**
 *@file Q-1.cpp
 *@author Anish Dey, Anish Walia, Shikhar Dhawale, Aniruddh Gupta
 *@date February 20,2020
 *@brief The driver function to test all other functions
 *
 *\mainpage Description
 *This code is the first task of the assignmnet. Through his code,we need to find strongly connected components in a directed graph using Depth First search(DFS) algorithm. 
 *
 * *\section func_sec Functionalities of this code
 *\subsection func1 DFS() 
 *This is a recursive function to print DFS starting from v
 *\subsection func2 getFinishingTime(vertices,visited,stack)
 *This function is mainly used to get the finishing time of the vertices when a DFS is implemented on this Graph in the form of stack. The top element of stack has the maximum finishing time
 *\subsection func3 addEdge(parent,child)
 *This function is mainly used to add a directed edge from vertex u to vertex v
 *\subsection func4 findSCCs()
 *The main function that finds and prints the strongly connected components.
 *\subsection func5 getReverse()
 * The function that returns reverse (or transpose) of the graph
*/

/**
 *@brief main() method
 *This function is the driver function to call other methods
*/

int main()
{
    freopen("L3.txt", "r", stdin);
    freopen("Q1_LO3.txt", "w", stdout);
    int V; /**<Number of Vertices in the Graph*/
    int E; /**<Number of Edges in the Graph*/
    cin >> V >> E;
    Graph g(V); /**<A graph varibale*/
    for (int i = 0; i < E; i++)
    {
        int parent; /**<Parent of the directed edge*/
        int child;  /**<Child of the directed edge*/
        cin >> parent >> child;
        g.addEdge(parent, child);
        //cout << "lol\n";
    }
    cout << "The Strongly Connected Components in the enterd Graph are: \n";
    g.findSCCs();
    cerr << "Total number of components= " << g.nos << "\n";
    cerr << "Completed in " << (clock() / CLOCKS_PER_SEC) << "secs\n";
    cout << "Total number of components= " << g.nos << "\n";
    cout << "Completed in " << (clock() / CLOCKS_PER_SEC) << "secs\n";
}
