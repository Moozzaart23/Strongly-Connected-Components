#include <bits/stdc++.h>
using namespace std;

#include "Q1.h"
/**
 *@file Q-1.cpp
 *@author Anish Dey, Anish Walia, Shikhar Dhawale, Aniruddh Gupta
 *@date February 20,2020
 *@brief Find Strongly Connected Components in a DIrected Graph
*/
set<int> x;
map<int, int> m;
int k = 0;
Graph::Graph(int V)
{
    this->V = V;            //initialises the number of vertices
    adj = new list<int>[V]; //allocates memory to "V" adjacency Lists
}

void Graph::DFS(int v, bool visited[])
{
    visited[v] = true; //mark the current node as visited
    for (auto y : m)
    {
        if (y.second == v)
        {
            cout << y.first << " ";
        }
    }
    //cout << v << " ";  //print the node

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) //iterate through all the vertices adjacent to the current node and call DFS for each of them
    {
        if (!visited[*i]) //if not visited, call DFS for this node
        {
            DFS(*i, visited);
        }
    }
}

Graph Graph::getReverse()
{
    Graph g(V); /**<A Graph variable for the complement graph*/
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    //cout << "lol\n";
    if (x.find(v) == x.end())
    {
        x.insert(v);
        m[v] = k++;
    }
    if (x.find(w) == x.end())
    {
        x.insert(w);
        m[w] = k++;
    }
    adj[m[v]].push_back(m[w]); // Add w to v’s list.
}

void Graph::getFinishingTime(int v, bool vis[], stack<int> &s)
{
    vis[v] = true; //Mark the current node as visited
    //cout << "lol4\n";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) //iterate through all the vertices adjacent to the current node and call DFS for each of them
    {
        if (!vis[*i]) //if not visited, call DFS for this node
        {
            getFinishingTime(*i, vis, s);
        }
    }

    s.push(v); //All vertices which could be reached by v are recurred by now, so push it into the stack to represent the finishing time
}

void Graph::findSCCs()
{
    /*for (auto u : x)
    {
        cout << u << " " << m[u] << "\n";
    }*/
    //cout << "lol\n";
    stack<int> s;            /**<A stack data structure variable*/
    bool *vis = new bool[V]; /**<visited array to get the finishing times*/
    for (int i = 0; i < V; i++)
    {
        vis[i] = false; //Mark all the vertices as unvisited at the beginning
    }

    for (int i = 0; i < V; i++) //Call the function for all the unvisited vertices one by one to get the finising times
    {
        if (vis[i] == false)
        {
            //cout << "lol3\n";
            getFinishingTime(i, vis, s);
        }
    }
    /*stack<int> s2 = s;
    while (s2.empty() == false)
    {
        cout << "lol2 ";
        int v = s2.top();
        cout << v << " ";
        s2.pop();
    }*/
    Graph g2 = getReverse(); /**<A Graph variable*/

    for (int i = 0; i < V; i++)
    {
        vis[i] = false; //Mark all the vertices as unvisited now to find the Strongly Connected Components
    }
    while (s.empty() == false) //process all the vertices in order of their finishing times
    {
        int v = s.top(); //Pop a vertex from the top of the stack
        //cout << "KK= " << v << " ";
        s.pop();
        if (vis[v] == false) //Print the strongly connected component of the popped vertex
        {
            g2.DFS(v, vis);
            nos = nos + 1;
            cout << "\n";
        }
    }
}
