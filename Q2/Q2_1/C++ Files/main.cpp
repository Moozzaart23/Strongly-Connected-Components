#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
#include "Q2.h"

/**
 *@file Q-2.cpp
 *@author Anish Dey, Anish Walia, Shikhar Dhawale, Aniruddh Gupta
 *@date February 23,2020
 *@brief The driver function to test all other functions
 *
 *\mainpage Description
 *This code is the second task of the assignmnet. Through his code,we need to find strongly connected components in a directed graph using Divide and Conquer algorithm given in the research paper
 *
 * *\section func_sec Functionalities of this code
 *\subsection func1 dfs()
 *This is a recursive function to print DFS starting from v
 *\subsection func2 rev()
 *The function that returns reverse (or transpose) of the graph
 *\subsection func3 addEdge(parent,child)
 *This function is mainly used to add a directed edge from vertex u to vertex v
 *\subsection func4 sub(AdjacencyList A,AdjacencyList B)
 *This function generates a graph which contains vertex which are there in  Graph A but not in Graph B
 *\subsection func5 Union(AdjacencyList A,AdjacencyList B)
 * This function generates a graph which contains vertex which are there in  Graph A or in Graph B
 *\subsection func6 intersect(AdjacencyList A,AdjacencyList B)
 * This function generates a graph which contains vertex which are there in  Graph A and also in Graph B
 *\subsection func7 desc(AdjacencyList G,vertex A)
 * This function generates a graph with vertex A and its descendants
 *\subsection func8 DCSC()
 * This function generates the strongly connected components of a graph recursively
*/

/**
 *@brief main() method
 *This function is the driver function to call other methods
*/

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("L3.txt", "r", stdin);
    freopen("Q2_LO3.txt", "w", stdout);
    ll n; /**<Number of Vertices in the Graph*/
    ll m; /**<Number of Edges in the Graph*/
    cin >> n >> m;
    Graph G(n); /**<A graph varibale*/
    //unordered_map<ll, vector<ll>> g;
    while (m--)
    {
        ll u, v; /**<vertices varibale*/
        cin >> u >> v;
        G.addEdge(u, v);
    }
    unordered_map<ll, vector<ll>> g = G.g;
    cout << "The Strongly Connected Components are\n";
    int x = G.DCSCUtil(g);
    cout << "Number of components= " << x << "\n";
    cout << "Completed in " << (1000 * clock() / CLOCKS_PER_SEC) << "\n";
    cerr << "Number of components= " << x << "\n";
    cerr << "Completed in " << (1000 * clock() / CLOCKS_PER_SEC) << "\n";
    return 0;
}
