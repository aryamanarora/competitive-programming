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

struct segment_tree {
    int n;
    vi maxi;

    segment_tree(int N, vi &s) : n(4 * N), maxi(4 * N) {
        build(s, 1, 0, N - 1);
    };

    void build(vi &a, int v, int tl, int tr) {
        if (tl == tr) {
            maxi[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);

            maxi[v] = max(maxi[v * 2], maxi[v * 2 + 1]);
        }
    };

    int get_max(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl and r == tr) {
            return maxi[v];
        }

        int tm = (tl + tr) / 2;
        return max(
            get_max(v * 2, tl, tm, l, min(r, tm)),
            get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    };

    void update(int v, int tl, int tr, int pos, int inc) {
        if (tl == tr) maxi[v] += inc;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v * 2, tl, tm, pos, inc);
            else update(v * 2 + 1, tm + 1, tr, pos, inc);
            maxi[v] = max(maxi[v * 2], maxi[v * 2 + 1]);
        }
    }
};

struct hld {
    int n;
    vi p, depth, heavy, head, pos, val;
    vector<vi> &g;
    int cur;
    unique_ptr<segment_tree> segtree;

    hld(int n, vector<vi> &g) : g(g), cur(0), heavy(n, -1), p(n), depth(n), head(n), pos(n) {
        dfs(0);
        decomp(0, 0);
        vi val(n, 0);
        segtree = make_unique<segment_tree>(n, val);
        this->n = n;
    };

    int dfs(int u) {
        int sz = 1, maxi = 0;
        for (auto v : g[u]) {
            if (v == p[u]) continue;
            p[v] = u; depth[v] = depth[u] + 1;
            int sz2 = dfs(v);
            sz += sz2;
            if (sz2 > maxi) maxi = sz2, heavy[u] = v;
        }
        return sz;
    };

    void decomp(int u, int h) {
        head[u] = h, pos[u] = cur++;
        if (heavy[u] != -1) decomp(heavy[u], h);
        for (auto v : g[u]) {
            if (v != p[u] and v != heavy[u]) decomp(v, v);
        }
    }

    int query(int u, int v) {
        int res = 0;
        for (; head[u] != head[v]; v = p[head[v]]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res = max(res, segtree->get_max(1, 0, n - 1, pos[head[v]], pos[v]));
        }
        if (depth[u] > depth[v]) swap(u, v);
        res = max(res, segtree->get_max(1, 0, n - 1, pos[u], pos[v]));
        return res;
    }

    void update(int u, int inc) {
        segtree->update(1, 0, n - 1, pos[u], inc);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vi> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    hld decomp(n, g);
    int q;
    cin >> q;
    while (q--) {
        char c; int a, b;
        cin >> c >> a >> b;
        if (c == 'G') {
            a--, b--;
            cout << decomp.query(a, b) << endl;
        }
        else {
            a--;
            decomp.update(a, b);
        }
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