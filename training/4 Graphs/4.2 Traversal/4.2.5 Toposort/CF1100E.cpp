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

struct edge {
    int v, w, id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    int lo = 0, hi = 0;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w; u--, v--;
        g[u].pb({v, w, i + 1});
        hi = max(hi, w);
    }
    hi++;

    function<bool(int, int, vector<bool>&, vector<bool>&)> has_cycles = [&](int u, int k, vector<bool> &vis, vector<bool> &st) {
        if (!vis[u]) {
            vis[u] = st[u] = true;
            for (auto &v : g[u]) {
                if (v.w <= k) continue;
                if (!vis[v.v] and has_cycles(v.v, k, vis, st)) return true;
                else if (st[v.v]) return true;
            }
        }
        st[u] = false;
        return false;
    };

    function<bool(int)> check = [&](int k) {
        vector<bool> vis(n, false), st(n, false);
        for (int i = 0; i < n; i++) {
            if (has_cycles(i, k, vis, st)) return true;
        }
        return false;
    };

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (!check(mid)) hi = mid;
        else lo = mid + 1;
    }

    vector<bool> vis(n, false); vi val(n); int ct = 0;
    function<void(int)> toposort = [&](int u) {
        vis[u] = true;
        for (auto &v : g[u]) {
            if (v.w <= lo) continue;
            if (!vis[v.v]) toposort(v.v);
        }
        val[u] = ct++;
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) toposort(i);
    }

    vi ans;
    for (int u = 0; u < n; u++) {
        for (auto &v : g[u]) if (val[u] < val[v.v]) ans.pb(v.id);
    }

    cout << lo << " " << ans.size() << endl;
    for (auto &x : ans) cout << x << " ";
    cout << endl;
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