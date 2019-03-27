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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi val(n); for (auto &x : val) cin >> x;
    vector<vi> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<map<int, ii>> ct(n);
    int ans = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        si pr;
        for (int i = 2; i * i <= val[u]; i++) {
            if (val[u] % i == 0) {
                pr.insert(i);
                ct[u][i] = {1, 1};
                while (val[u] % i == 0) val[u] /= i;
            }
        }
        if (val[u] != 1) {
            pr.insert(val[u]);
            ct[u][val[u]] = {1, 1};
        }
        for (auto &v : g[u]) {
            if (v == p) continue;
            dfs(v, u);
            for (auto &pri : pr) {
                if (ct[v].count(pri)) {
                    if (ct[v][pri].f + 1 >= ct[u][pri].f) {
                        ct[u][pri].s = ct[u][pri].f;
                        ct[u][pri].f = ct[v][pri].f + 1;
                    }
                    else if (ct[v][pri].f + 1 > ct[u][pri].s) {
                        ct[u][pri].s = ct[v][pri].f + 1;
                    }
                }
            }
        }
        // cout << u << endl;
        for (auto &x : ct[u]) {
            // cout << x.f << ": " << x.s.f << " " << x.s.s << endl;
            ans = max(ans, x.s.f + x.s.s - 1);
        }
        // cout << endl;
    };

    dfs(0, -1);

    cout << ans << endl;
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