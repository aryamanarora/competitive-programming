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

const int INF = numeric_limits<int>::max();
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    vi val(n); for (auto &x : val) cin >> x;
    vector<vi> g(n), gr(n);
    cin >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v; u--, v--;
        g[u].pb(v);
        gr[v].pb(u); // transposed
    }

    // Kosaraju's algorithm, O(V + E)
    vector<bool> vis(n, false);
    vi order;
    
    function<void(int)> dfs1 = [&](int u) {
        vis[u] = true;
        for (auto &v : g[u]) if (!vis[v]) dfs1(v);
        order.pb(u);
    };

    for (int i = 0; i < n; i++) if (!vis[i]) dfs1(i);

    vi component(n, -1), c; int ct = 0;

    function<void(int)> dfs2 = [&](int u) {
        component[u] = ct;
        c.pb(u);
        for (auto &v : gr[u]) if (component[v] == -1) dfs2(v);
    };

    for (int i = n - 1; i >= 0; i--) {
        if (component[order[i]] == -1) {
            dfs2(order[i]);
            ct++;
        }
    }

    // smallest value in each SCC
    vi mini(ct, INF), ways(ct);
    for (int i = 0; i < n; i++) {
        if (val[i] < mini[component[i]]) {
            ways[component[i]] = 1;
            mini[component[i]] = val[i];
        }
        else if (val[i] == mini[component[i]]) {
            ways[component[i]]++;
        }
    }

    ll cost = 0, ans = 1;
    for (int i = 0; i < ct; i++) {
        cost += mini[i];
        ans *= ways[i]; ans %= MOD;
    }

    cout << cost << " " << ans << endl;
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