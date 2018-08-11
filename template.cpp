#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

inline namespace graph {
    struct undirected_graph_list {
        unsigned long V; // vertices
        unsigned long E; // edges
        vector<vector<int>> list; // adjacency list

        undirected_graph_list(int _V) {
            V = _V;
            list.resize(V);
            E = 0;
        }

        void add_edge(int i, int j) {
            list[i].push_back(i);
            list[j].push_back(j);
        }
        void add_vertices(int _V) {
            V += _V;
            list.resize(list.size() + _V);
        }
        void is_edge(int i, int j) {
            if (list[i].find(j) != list[i].end()) return true;
            else return false;
        }
    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}