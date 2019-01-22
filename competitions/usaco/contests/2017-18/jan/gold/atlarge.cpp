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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("atlarge.in");
    ofstream cout("atlarge.out");

    int n, k, u, v;
    cin >> n >> k;
    g.resize(n);
    k--;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vi dist(n, -1);
    dist[k] = 0;
    function<void(int, int)> dfs1 = [&](int u, int p) {
        for (auto &v : g[u]) {
            if (v == p) continue;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                dfs1(v, u);
            }
        }
    };
    dfs1(k, -1);

    vi dist_leaf(n, -1);
    function<void(int, int)> dfs2 = [&](int u, int p) {
        if (g[u].size() == 1) dist_leaf[u] = 0;
        for (auto &v : g[u]) {
            if (v == p) continue;
            dfs2(v, u);
            if (dist_leaf[u] == -1) dist_leaf[u] = dist_leaf[v] + 1;
            else dist_leaf[u] = min(dist_leaf[u], dist_leaf[v] + 1);
        }
    };
    dfs2(k, -1);

    function<int(int, int)> dfs3 = [&](int u, int p) {
        if (dist_leaf[u] <= dist[u]) return 1;
        int res = 0;
        for (auto &v : g[u]) {
            if (v == p) continue;
            res += dfs3(v, u);
        }
        return res;
    };

    cout << dfs3(k, -1) << endl;
}

/*
USE LONG LONG!!!!
*/