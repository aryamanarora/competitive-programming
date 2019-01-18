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
typedef vector<bool> vb;

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;

typedef vector<vi> vvi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vii> g(n); vi add(n);
    for (auto &x : add) cin >> x;
    for (int i = 0, u, v, w; i < n - 1; i++) {
        cin >> u >> v >> w;
        u--; v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    ll ans = 0;
    function<ll(int, int)> dfs = [&](int u, int p) -> ll {
        ll f = 0, s = 0;
        for (auto &v : g[u]) {
            if (v.f == p) continue;
            ll res = dfs(v.f, u) - v.s;
            if (res > 0) {
                if (res >= f) s = f, f = res;
                else if (res > s) s = res;
            }
        }
        // cout << u + 1 << ": " << f << " " << s << endl;
        ans = max(ans, f + add[u] + s);
        return f + add[u];
    };

    dfs(0, -1);

    cout << ans << endl;
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