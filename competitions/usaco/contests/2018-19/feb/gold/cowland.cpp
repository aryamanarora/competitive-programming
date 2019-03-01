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

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};
// source: https://cp-algorithms.com/graph/lca.html

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("cowland.in");
    ofstream cout("cowland.out");

    int n, q;
    cin >> n >> q;
    vi val(n); for (auto &x : val) cin >> x;
    vector<vi> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vi parent(n);

    function<void(int, int)> dfs = [&](int u, int p) {
        parent[u] = p;
        for (auto &v : g[u]) {
            if (v == p) continue;
            dfs(v, u);
        }
    };

    dfs(0, -1);

    LCA lca(g);

    vi xorsum(n);

    function<void(int, int)> dfs2 = [&](int u, int p) {
        if (p != -1) xorsum[u] ^= xorsum[p];
        xorsum[u] ^= val[u];
        for (auto &v : g[u]) {
            if (v == p) continue;
            dfs2(v, u);
        }
    };

    function<void(int, int, int)> update = [&](int u, int pos, int up) {
        xorsum[u] ^= val[pos];
        xorsum[u] ^= up;
        for (auto &v : g[u]) {
            if (v == parent[u]) continue;
            update(v, pos, up);
        }
    };

    dfs2(0, -1);

    for (int i = 0, j, u, v; i < q; i++) {
        cin >> j >> u >> v, u--, v--;
        if (j == 2) {
            int mid = lca.lca(u, v);
            cout << (xorsum[u] ^ xorsum[v] ^ val[mid]) << endl;
        }
        else {
            v++;
            update(u, u, v);
            val[u] = v;
        }
        // for (auto &x : xorsum) cout << x << " ";
        // cout << endl;
    }
}

/*
USE LONG LONG!!!!

:pray: :fishy15:
:pray: :summitosity:
:pray: :prodakcin:

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