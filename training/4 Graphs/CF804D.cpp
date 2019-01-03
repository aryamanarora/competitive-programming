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

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

struct disjoint_set {
    int n;
    vi parent; vl size;

    disjoint_set(int N) : n(N), size(N), parent(N) {
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_union(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (b != a) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            size[b] = 0;
        }
    }
};

ll dfs_1(int u, int par, vector<vi> &g, vl &maxd) {
    for (auto v : g[u]) {
        if (v != par) maxd[u] = max(maxd[u], 1 + dfs_1(v, u, g, maxd));
    }
    return maxd[u];
}

void dfs_2(int u, int par, int set, ll pardist, vector<vi> &g, vl &maxd, vl &total) {
    int first = -1, second = -1;
    for (auto v : g[u]) {
        if (v == par) continue;
        if (first == -1) first = v;
        else if (maxd[v] > maxd[first]) {
            second = first;
            first = v;
        }
        else if (maxd[v] > maxd[second]) second = v;
    }
    total[set] += max(maxd[first] + 1, pardist);
    for (auto v : g[u]) {
        if (v == par) continue;
        if (v == first) dfs_2(v, u, set, max(pardist + 1, maxd[second] + 2), g, maxd, total);
        else dfs_2(v, u, set, max(pardist + 1, maxd[first] + 2), g, maxd, total);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vi> g(n);
    disjoint_set dsu(n);
    for (int i = 0; i < n; i++) dsu.make_set(i);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].pb(v); g[v].pb(u);
        dsu.make_union(u, v);
    }
}

/*
USE LONG LONG!!!!

          .=     ,        =.
  _  _   /'/    )\,/,/(_   \ \
   `//-.|  (  ,\\)\//\)\/_  ) |
   //___\   `\\\/\\/\/\\///'  /
,-"~`-._ `"--'_   `"""`  _ \`'"~-,_
\       `-.  '_`.      .'_` \ ,-"~`/
 `.__.-'`/   (-\        /-) |-.__,'
   ||   |     \O)  /^\ (O/  | .        <-  BESSIE THE COW
   `\\  |         /   `\    /
     \\  \       /      `\ /
      `\\ `-.  /' .---.--.\
        `\\/`~(, '()      ('
         /(O) \\   _,.-.,_)    
        //  \\ `\'`      /
       / |  ||   `""""~"`
     /'  |__||
           `o
*/