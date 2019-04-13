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

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct lca {
    int n;
    vi height, dfs_order, start, segtree, dist;

    lca(vector<vi> &g) : n(g.size()), height(n), dist(n), start(n) {
        dfs(0, -1, g, 0, 0);
        segtree.resize(dfs_order.size() * 4);
        build(1, 0, dfs_order.size() - 1);
    }

    void dfs(int u, int p, vector<vi> &g, int d, int h) {
        dist[u] = d;
        height[u] = h;
        start[u] = dfs_order.size();
        dfs_order.push_back(u);
        for (auto &v : g[u]) {
            if (v == p) continue;
            dfs(v, u, g, d + 1, h + 1);
            dfs_order.push_back(u);
        }
    }

    void build(int u, int l, int r) {
        if (l == r) {
            segtree[u] = dfs_order[l];
        }
        else {
            int mid = (l + r) / 2;
            build(u * 2, l, mid);
            build(u * 2 + 1, mid + 1, r);
            segtree[u] = min(
                mp(height[segtree[u * 2]], segtree[u * 2]),
                mp(height[segtree[u * 2 + 1]], segtree[u * 2 + 1])
            ).s;
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

    int query(int u, int v) {
        int left = start[u], right = start[v];
        if (left > right)
            swap(left, right);
        int LCA = query(1, 0, dfs_order.size() - 1, left, right);
        return LCA;
    }
};

int dfs(int u, int p, vector<vi> &g, vi &add, vi &rem, vi &ans) {
    ans[u] += add[u];
    for (auto &v : g[u]) {
        if (v == p) continue;
        ans[u] += dfs(v, u, g, add, rem, ans);
    }
    ans[u] -= rem[u];
    return ans[u] - rem[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vi> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }


    lca LCA(g);

    vi add(n), rem(n);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, u--, v--;
        int l = LCA.query(u, v);
        add[u] += 1;
        add[v] += 1;
        rem[l] += 1;
    }

    vi ans(n);
    dfs(0, -1, g, add, rem, ans);

    for (auto &x : ans) cout << x << " ";
    cout << endl;
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