/*
ID: aryaman4
TASK: concom
LANG: C++14
*/

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

const int MAX = 101;

inline namespace graph {
    struct directed_graph_list {
        unsigned long V; // vertices
        unsigned long E; // edges
        vector<vii> list; // adjacency list

        directed_graph_list(int _V) {
            V = _V;
            list.resize(_V);
            E = 0;
        }

        void add_edge(int i, int j, int cost) {
            list[i].push_back(mp(j, cost));
            E++;
        }
    };
}

graph::directed_graph_list g(MAX);
map<int, int> weight;
map<int, bool> visited;

void dfs(int head_node, int node) {
    visited[node] = true;
    cout << node << " ";
    for (auto &child : g.list[node]) {
        if (!visited[child.f]) {
            weight[child.f] += child.s;
            if (weight[child.f] > 50) dfs(head_node, child.f);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("concom.in");
    int n;
    fin >> n;
    int i, j, p;
    vii ans;
    for (int ct = 0; ct < n; ct++) {
        fin >> i >> j >> p;
        g.add_edge(i, j, p);
    }

    vii control;
    for (int i = 1; i < MAX; i++) {
        dfs(i, i);
        for (auto &x : weight) {
            if (x.s > 50) control.pb(mp(i, x.f));
        }
        cout << endl;
        visited.clear();
        weight.clear();
    }

    ofstream fout("concom.out");
    sort(control.begin(), control.end());
    for (auto &x : control) {
        fout << x.f << " " << x.s << endl;
    }
    fout.close();
}