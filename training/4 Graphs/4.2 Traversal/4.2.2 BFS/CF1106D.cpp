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
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, u--, v--;
        g[u].pb(v); g[v].pb(u);
    }

    priority_queue<int, vi, greater<int>> ac; vi ans; vector<bool> used(n, false);
    ac.push(0);
    while (!ac.empty()) {
        int u = ac.top(); ac.pop();
        if (used[u]) continue;
        ans.pb(u);
        used[u] = true;
        for (auto &v : g[u]) {
            if (!used[v]) ac.push(v);
        }
    }

    for (auto &x : ans) cout << x + 1 << " ";
    cout << endl;
}

/*
USE LONG LONG!!!!

:pray: :fishy15:
:pray: :summitosity:

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