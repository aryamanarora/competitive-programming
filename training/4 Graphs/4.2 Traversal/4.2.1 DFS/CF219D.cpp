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
    vector<vii> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        g[u].pb({v, 1});
        g[v].pb({u, 0});
    }

    vii cur;
    
    function<void(int, int)> dfs1 = [&](int u, int p) {
        for (auto &v : g[u]) {
            if (v.f == p) continue;
            if (v.s == 0) cur.pb({u, v.f});
            dfs1(v.f, u);
        }
    };

    dfs1(0, -1);

    int mini = cur.size(), curr = cur.size();
    si ans;

    function<void(int, int)> dfs2 = [&](int u, int p) {
        if (curr < mini) {
                mini = curr;
                ans.clear();
                ans.insert(u);
        }
        else if (curr <= mini) ans.insert(u);
        for (auto &v : g[u]) {
            if (v.f == p) continue;
            if (v.s == 0) curr--;
            else curr++;
            dfs2(v.f, u);
            if (v.s == 0) curr++;
            else curr--;
        }
    };

    dfs2(0, -1);

    cout << mini << endl;
    for (auto &x : ans) cout << x + 1 << " ";
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