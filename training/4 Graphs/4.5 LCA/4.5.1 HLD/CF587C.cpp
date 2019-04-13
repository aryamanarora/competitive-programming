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

vi minim(vi &l, vi &r) {
    vi res;
    int i = 0, j = 0;
    while (res.size() < 10) {
        if (i < l.size() and j < r.size()) {
            if (l[i] < r[j]) res.push_back(l[i]), i++;
            else res.push_back(r[j]), j++;
        }
        else if (i < l.size()) res.push_back(l[i]), i++;
        else if (j < r.size()) res.push_back(r[j]), j++;
        else break;
    }
    return res;
}

struct segment_tree {
    int n;
    vector<vi> mini;

    segment_tree(int N, vector<vi> &s) : n(4 * N), mini(4 * N) {
        build(s, 1, 0, N - 1);
    };

    void build(vector<vi> &a, int v, int tl, int tr) {
        if (tl == tr) {
            mini[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);

            int i = 0, j = 0;
            mini[v] = minim(mini[v * 2], mini[v * 2 + 1]);
        }
    };

    vi get_min(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            vi a;
            return a;
        }
        if (l == tl and r == tr) {
            return mini[v];
        }

        int tm = (tl + tr) / 2;
        vi ll = get_min(v * 2, tl, tm, l, min(r, tm)),
           rr = get_min(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        vi ans = minim(ll, rr);
        return ans;
    };
};

struct hld {
    int n;
    vi p, depth, heavy, head, pos, val;
    vector<vi> &g;
    int cur;
    unique_ptr<segment_tree> segtree;

    hld(int n, vector<vi> &g, vector<vi> &a) : g(g), cur(0), heavy(n, -1), p(n), depth(n), head(n), pos(n) {
        dfs(0);
        decomp(0, 0);
        segtree = make_unique<segment_tree>(n, a);
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

    vi query(int u, int v) {
        vi res;
        for (; head[u] != head[v]; v = p[head[v]]) {
            cout << u << " " << v << endl;
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            vi q = segtree->get_min(1, 0, n - 1, pos[head[v]], pos[v]);
            res = minim(res, q);
        }
        if (depth[u] > depth[v]) swap(u, v);
        vi q = segtree->get_min(1, 0, n - 1, pos[u], pos[v]);
        res = minim(res, q);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vi> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vi> a(n);
    for (int i = 0, j; i < m; i++) {
        cin >> j, j--;
        a[j].push_back(i);
    }

    hld graph(n, g, a);
    for (int i = 0, u, v, a; i < n; i++) {
        cin >> u >> v >> a, u--, v--;
        vi ans = graph.query(u, v);
        int k = min(a, static_cast<int>(ans.size()));
        cout << k << " ";
        for (int j = 0; j < k; j++) cout << ans[j] + 1 << " ";
        cout << '\n';
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