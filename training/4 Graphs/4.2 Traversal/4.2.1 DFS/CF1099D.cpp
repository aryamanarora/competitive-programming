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

ll ans = 0;

void dfs(int u, int sum, vector<vi> &g, vi &s) {
    if (s[u] != -1) {
        if (s[u] >= sum) {
            ans += (s[u] - sum);
            sum = s[u];
        }
        else {
            ans = -1;
            return;
        } 
    }
    else if (g[u].size() != 0) {
        int oldsum = sum;
        sum = -1;
        for (auto &v : g[u]) {
            if (sum == -1) sum = s[v];
            else sum = min(sum, s[v]);
        }
        if (sum < oldsum) {
            ans = -1;
            return;
        }
        ans += (sum - oldsum);
    }
    // cout << u << ": " << sum << endl;
    for (auto &v : g[u]) {
        dfs(v, sum, g, s);
        if (ans == -1) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vi> g(n); vi s(n);
    for (int i = 1, u; i < n; i++) {
        cin >> u;
        u--;
        g[u].pb(i);
    }
    for (auto &x : s) cin >> x;

    dfs(0, 0, g, s);
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