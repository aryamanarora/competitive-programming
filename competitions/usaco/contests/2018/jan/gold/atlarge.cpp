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

vector<vi> g;

void dfs(int u, vi &dist) {
    for (auto v : g[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            dfs(v, dist);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("atlarge.in");
    ofstream fout("atlarge.out");

    int n, k, u, v;
    fin >> n >> k;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        fin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vi dist(n, -1);
    dist[k] = 0;
    dfs(k, dist);
}

/*
USE LONG LONG!!!!
*/