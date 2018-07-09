#include <bits/stdc++.h>

using namespace std;

class undirected_graph {
    int n; // number of vertices
    list<int> *adj; // adjacency list

    void add_edge(int u, int v) {
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
};

undirected_graph::graph(int n)
{
    this->n = n;
    adj = new list<int>[n];
}