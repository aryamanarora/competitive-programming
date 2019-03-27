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

void dfs1(int u, int p, vector<vi> &g, vl &ct, vl &sum) {
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs1(v, u, g, ct, sum);
        ct[u] += 1 + ct[v];
        sum[u] += sum[v];
    }
    sum[u] += ct[u];
}

void dfs2(int u, int p, vector<vi> &g, vl &ans, vl &sum, vl &ct, ll cur) {
    ans[u] = sum[0] + cur;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs2(v, u, g, ans, sum, ct, cur - 2 * ct[v] + ct[0]);
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

    vl ct(n), sum(n);
    dfs1(0, -1, g, ct, sum);
    for (auto &x : ct) x++;

    vl ans(n);
    dfs2(0,-1, g, ans, sum, ct, 0);

    for (auto &x : ans) cout << x << " ";
    cout << endl;
}

/*
1 2
1 3
1 4

    1 2 3 4
sum 3 0 0 0
ct  3 0 0 0

sum 0 5 0 0
ct  0 3 0 0


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