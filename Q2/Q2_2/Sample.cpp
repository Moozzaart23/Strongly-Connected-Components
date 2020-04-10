#include <bits/stdc++.h>
using namespace std;
int v;
vector<int> adj[1500000];
vector<int> vis(1500000, 0);
vector<int> voo(1500000, 0);
vector<int> pred[1500000];
vector<int> desc[1500000];
void dfs(int v)
{
    vis[v] = 1;
    for (int j = 0; j < adj[v].size(); j++)
    {
        if (!vis[adj[v][j]])
            dfs(adj[v][j]);
    }
}
void get(vector<int> vo)
{
    for (int i = 0; i < v; i++)
    {
        pred[i].clear();
        desc[i].clear();
    }
    for (int i = 0; i < v; i++)
    {
        if (vo[i] == 0)
        {
            for (int j = 0; j < v; j++)
                vis[j] = 0;
            dfs(i);
            for (int j = 0; j < v; j++)
            {
                if (vis[j] == 1)
                {
                    pred[j].push_back(i);
                    desc[i].push_back(j);
                }
            }
            for (int j = 0; j < v; j++)
                vis[j] = 0;
        }
    }
}
void dcsc(vector<int> vo)
{
    get(vo);
    int c = 0;
    for (int i = 0; i < voo.size(); i++)
    {
        if (voo[i] == 1)
            c++;
    }
    if (c != v)
    {
        int y = -1;
        for (int i = 0; i < v; i++)
            if (vo[i] == 0)
            {
                y = i;
                break;
            }
        if (y == -1)
            return;
        vector<int> vector1 = pred[y];
        vector<int> vector2 = desc[y];
        vector<int> common;
        vector<int> un;
        vector<int> vv(vector1.size() + vector2.size());
        vector<int>::iterator it, st;
        it = set_intersection(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), vv.begin());
        int z = 0;
        for (st = vv.begin(); st != it and voo[*st] != 1; ++st)
            cout << *st << " ", voo[*st] = 1, z = 1;
        if (z == 1)
            cout << "\n";

        for (int i = 0; i < vector1.size(); i++)
        {
            un.push_back(vector1[i]);
        }
        for (int i = 0; i < vector2.size(); i++)
        {
            if (find(un.begin(), un.end(), vector2[i]) == un.end())
                un.push_back(vector2[i]);
        }
        vector<int> a(v, 1);
        vector<int> b(v, 1);
        vector<int> c(v, 1);
        for (int i = 0; i < v; i++)
        {
            if (find(vector1.begin(), vector1.end(), i) != vector1.end() and voo[i] == 0)
                a[i] = 0;
            if (find(vector2.begin(), vector2.end(), i) != vector2.end() and voo[i] == 0)
                b[i] = 0;
            if (find(un.begin(), un.end(), i) == un.end())
                c[i] = 0;
        }
        dcsc(a);
        dcsc(b);
        dcsc(c);
    }
    else
    {
        int s = 0;
        for (int i = 0; i < v; i++)
        {
            if (voo[i] == 0)
                cout << i << " ", voo[i] = 1, s = 1;
        }
        if (s == 1)
            cout << "\n";
        return;
    }
}

int main()
{
    int e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<int> o(v, 0);
    cout << "The Strongly Connected Components are\n";
    dcsc(o);
}