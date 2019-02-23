#include <bits/stdc++.h>

using namespace std;

#define int long long

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("dirtraverse.in");
    ofstream cout("dirtraverse.out");

    int n;
    cin >> n;
    vi len(n); vector<vi> g(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        len[i] = s.length();
        int v;
        cin >> v;
        for (int k = 0, j; k < v; k++) {
            cin >> j;
            g[i].pb(j - 1);
        }
        if (v != 0) len[i]++;
    }

    /*
    for (int u = 0; u < n; u++) {
        cout << len[u] << ": ";
        for (auto &v : g [u]) cout << v << " ";
        cout << endl;
    }
    */

    vi maxlen(n), ct(n);

    function<void(int)> dfs1 = [&](int u) {
        if (g[u].size() == 0) {
            maxlen[u] = 0;
            ct[u] = 1;
            return;
        }
        for (auto &v : g[u]) {
            dfs1(v);
            maxlen[u] += len[v] * ct[v] + maxlen[v];
            ct[u] += ct[v];
        }
    };

    dfs1(0);

    int ans = maxlen[0];
    function<void(int, int)> dfs2 = [&](int u, int cur) {
        // cout << u << " " << ct[u] << " " << cur << endl;
        ans = min(ans, cur);
        for (auto &v : g[u]) {
            if (g[v].size() == 0) continue;
            dfs2(v, cur - (len[v] * ct[v]) + (ct[0] - ct[v]) * 3);
        }
    };

    dfs2(0, maxlen[0]);

    cout << ans << endl;
}

/*
folder1/file1
folder1/folder2/file2
folder3/file3
file4

8 5
8 8 5
8 5
5

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