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
    struct directed_graph_list {
        unsigned long V; // vertices
        unsigned long E; // edges
        vector<vector<int>> list; // adjacency list

        undirected_graph_list(int _V = 0) {
            V = _V;
            list.resize(V + 1);
            E = 0;
        }

        void add_edge(int i, int j) {
            list[i].push_back(j);
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

int max_depth(graph::directed_graph_list &g, int node) {
    if (g.list[node].size() == 0) return 0;
    int ans = 0;
    for (auto &child : g.list[node]) {
        ans = max(ans, max_depth(g, child) + 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;
    graph::directed_graph_list g(n + 1);
    int a;
    vi top;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a != -1) g.add_edge(a, i);
        else top.pb(i);
    }

    int ans = 0;
    for (auto &x : top) {
        ans = max(ans, max_depth(g, x));
    }
    cout << ans << endl;
}