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
    vector<bool> pr(n);
    for (int i = 0, j; i < n; i++) {
        cin >> j;
        pr[i] = j;
    }
    vector<vi> dep(n); vector<bool> has_dep(n, false);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        dep[v].pb(u);
        has_dep[u] = true;
    }

    vector<bool> vis(n); vi val(n); vi order;
    function<void(int)> toposort = [&](int u) {
        // cout << u << endl;
        vis[u] = true;
        for (auto &v : dep[u]) {
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

    vi ans(n, 0);
    for (auto &u : order) {
        // cout << has_dep[u] << " ";
        if (!has_dep[u] and pr[u] == 1) ans[u] = 1;
        for (auto &v : dep[u]) {
            // cout << u << " " << v << endl;
            if (pr[v] != pr[u] and pr[v] == 1) ans[v] = max(ans[u] + 1, ans[v]);
            else ans[v] = max(ans[u], ans[v]);
        }
    }
    // cout << endl << endl;
    // for (auto &x : ans) cout << x << " ";
    // cout << endl;
    cout << *max_element(ans.begin(), ans.end()) << endl;
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