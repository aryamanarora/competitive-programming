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
    cin >> n, m;
    vector<vi> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vi sz(n, 1); vector<bool> vis(n, false);
    function<void(int, int)> dfs_size = [&](int u, int p) {
        for (auto &v : g[u]) {
            if (v == p) continue;
            dfs_size(v, u);
            sz[u] += sz[v];
        }
    };

    dfs_size(0, -1);

    // for (auto &x : sz) cout << x << " ";
    // cout << endl;

    function<void(int, int)> centroid_decomp = [&](int u, int nn) {
        // cout << u << endl;
        // for (auto &x : sz) cout << x << " ";
        // cout << endl;

        int maxi = -1;
        for (auto &v : g[u]) {
            if (vis[v]) continue;
            if (maxi == -1) maxi = v;
            else if (sz[maxi] < sz[v]) maxi = v;
        }
        if (maxi == -1) {
            vis[u] = true;
            sz[u] = 0;
        }
        else if (sz[maxi] > nn / 2) {
            sz[u] -= sz[maxi];
            sz[maxi] += sz[u];
            centroid_decomp(maxi, nn);
        }
        else {
            vis[u] = true;
            sz[u] = 0;
            for (auto &v : g[u]) {
                if (!vis[v]) centroid_decomp(v, sz[v]);
            }
        }
    };

    centroid_decomp(0, 'A', n);

    for (auto &x : lb) cout << x << " ";
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