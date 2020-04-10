#include <bits/stdc++.h>
using namespace std;

#include "Q2.h"
#define ll int64_t

/**
 *@file Q-2.cpp
 *@author Anish Dey, Anish Walia, Shikhar Dhawale, Aniruddh Gupta
 *@date February 23,2020
 *@brief Find Strongly Connected Components in a Directed Graph using the divide and conquer approach
*/
int nos = 0;
Graph::Graph(int x)
{
    this->v = x;
}
void Graph::addEdge(ll x, ll y)
{
    g[x].push_back(y);
    g[y];
}
void Graph::dfs(unordered_map<ll, vector<ll>> g, ll v, unordered_map<ll, vector<ll>> &ans, unordered_map<ll, ll> &vis)
{
    vis[v] = 1;
    ans[v].push_back(0);
    for (auto e : g[v])
    {
        if (!vis[e])
            dfs(g, e, ans, vis);
    }
}
unordered_map<ll, vector<ll>> Graph::rev(unordered_map<ll, vector<ll>> g)
{
    unordered_map<ll, vector<ll>> r;
    for (auto m : g)
    {
        auto l = m.second;
        for (ll e : l)
        {
            r[e].push_back(m.first);
        }
    }
    return r;
}
unordered_map<ll, vector<ll>> Graph::sub(unordered_map<ll, vector<ll>> a, unordered_map<ll, vector<ll>> b)
{
    unordered_map<ll, vector<ll>> c;
    for (auto m : a)
    {
        if (b.find(m.first) == b.end())
        {
            c[m.first].push_back(0);
        }
    }
    for (auto &m : c)
    {
        m.second.clear();
        for (ll e : a[m.first])
        {
            if (c.find(e) != c.end())
                m.second.push_back(e);
        }
    }
    return c;
}
unordered_map<ll, vector<ll>> Graph::Union(unordered_map<ll, vector<ll>> a, unordered_map<ll, vector<ll>> b)
{
    unordered_map<ll, vector<ll>> c;
    for (auto m : a)
    {
        c[m.first] = m.second;
    }
    for (auto m : b)
    {
        c[m.first] = m.second;
    }
    return c;
}
unordered_map<ll, vector<ll>> Graph::intersect(unordered_map<ll, vector<ll>> a, unordered_map<ll, vector<ll>> b)
{
    unordered_map<ll, vector<ll>> c;
    for (auto m : a)
    {
        if (b.find(m.first) != b.end())
        {
            c[m.first].push_back(0);
        }
    }
    for (auto &m : c)
    {
        m.second.clear();
        for (ll e : a[m.first])
        {
            if (c.find(e) != c.end())
                m.second.push_back(e);
        }
    }
    return c;
}
unordered_map<ll, vector<ll>> Graph::Desc(unordered_map<ll, vector<ll>> g, ll v)
{
    unordered_map<ll, ll> vis;
    unordered_map<ll, vector<ll>> a;
    dfs(g, v, a, vis);
    for (auto &m : a)
    {
        m.second.clear();
        for (auto l : g[m.first])
        {
            if (a.find(l) != a.end())
                m.second.push_back(l);
        }
    }
    return a;
}
void Graph::DCSC(unordered_map<ll, vector<ll>> g)
{
    ll flag = 1;
    if (g.empty())
        return;
    for (auto m : g)
    {
        if (m.second.size())
            flag = 0;
    }
    if (flag)
    {
        for (auto m : g)
        {
            cout << m.first << "\n";
            nos = nos + 1;
        }
        //nos = nos + 1;
        return;
    }
    ll v = (*g.begin()).first;
    auto desc = Desc(g, v);
    auto pred = Desc(rev(g), v);
    auto SCC = intersect(pred, desc);
    for (auto m : SCC)
    {
        cout << m.first << " ";
    }
    nos = nos + 1;
    cout << "\n";
    unordered_map<ll, vector<ll>> a = sub(pred, SCC);
    unordered_map<ll, vector<ll>> b = sub(desc, SCC);
    unordered_map<ll, vector<ll>> c = sub(g, Union(pred, desc));
    DCSC(a);
    DCSC(b);
    DCSC(c);
    //cerr << nos << "\n";
}
int Graph::DCSCUtil(unordered_map<ll, vector<ll>> g)
{
    DCSC(g);
    return nos;
}
