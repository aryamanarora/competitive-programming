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

void dfs1(int u, int p, vector<vi> &g, vector<pair<ii, ii>> &d) {
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs1(v, u, g, d);
        if (d[u].f.f == -1) d[u].f = {v, d[v].f.s + 1};
        else if (d[u].s.f == -1) d[u].s = {v, d[v].f.s + 1};
        else if (d[v].f.s + 1 >= d[u].f.s) {
            d[u].s = d[u].f;
            d[u].f = {v, d[v].f.s + 1};
        }
        else if (d[v].f.s + 1 >= d[u].s.s) d[u].s = {v, d[v].f.s + 1};
    }
}

void dfs2(int u, int p, vector<vi> &g, vector<pair<ii, ii>> &d, vi &ans, int cur) {
    ans[u] = max(d[u].f.s, cur);
    for (auto &v : g[u]) {
        if (v == p) continue;
        if (v == d[u].f.f) dfs2(v, u, g, d, ans, max(cur, d[u].s.s) + 1);
        else dfs2(v, u, g, d, ans, max(cur, d[u].f.s) + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<pair<ii, ii>> depth(n);
    dfs1(0, -1, g, depth);

    vi ans(n);
    dfs2(0, -1, g, depth, ans, 0);

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