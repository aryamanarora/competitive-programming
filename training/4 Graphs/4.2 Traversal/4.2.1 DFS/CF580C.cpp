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
            list.resize(V + 1);
            E = 0;
        }
        void add_edge(int i, int j) {
            list[i].push_back(j);
            list[j].push_back(i);
        }
    };
}

map<int, bool> cat;
map<int, bool> visited;
int n, m, ans = 0;

void dfs(const graph::undirected_graph_list &g, int node, int cats) {
    visited[node] = true;
    
    if (cat[node]) cats++;
    else cats = 0;
    if (cats > m) return;

    if (g.list[node].size() == 1 and node != 1) ans++;
    for (auto &x : g.list[node]) {
        if (!visited[x]) dfs(g, x, cats);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == 1) cat[i] = true;
        else cat[i] = false;
    }
    
    graph::undirected_graph_list g(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        g.add_edge(a, b);
    }
    
    /*
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto x : g.list[i]) cout << x << " ";
        cout << endl;
    }
    */
    
    dfs(g, 1, 0);
    cout << ans << endl;
}