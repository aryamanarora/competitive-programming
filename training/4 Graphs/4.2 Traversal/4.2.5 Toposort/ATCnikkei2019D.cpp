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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vi> g(n);
    for (int i = 0, u, v; i < n - 1 + m; i++) {
        cin >> u >> v;
        u--; v--; g[u].pb(v);
    }

    vector<bool> vis(n); vi val(n); vi order;
    function<void(int)> toposort = [&](int u) {
        // cout << u << endl;
        vis[u] = true;
        for (auto &v : g[u]) {
            if (!vis[v]) toposort(v);
        }
        order.pb(u);
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) toposort(i);
    }

    reverse(order.begin(), order.end());
    // for (auto &x : order) cout << x << " ";
    // cout << endl;

    /*
    for (auto &x : order) cout << x + 1 << " ";
    cout << endl;
    */

    vi pos(n);
    for (int i = 0; i < n; i++) pos[order[i]] = i;

    vi par(n, -1);
    for (int i = 0; i < n; i++) {
        for (auto &v : g[i]) {
            if (par[v] == -1) par[v] = i;
            else if (pos[i] > pos[par[v]]) par[v] = i;
        }
    }

    for (auto &x : par) cout << x + 1 << endl;
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