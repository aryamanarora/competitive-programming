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
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

struct node {
    int u, parent, dist;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("statiuni.in");
    ofstream cout("statiuni.out");

    int n, k;
    cin >> n >> k;
    vii dist(n, {-1, -1}); vi ct(n, 0);
    vector<vi> g(n);
    
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    queue<node> bfs;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            bfs.push({i, -1, 0});
            ct[i]++;
            dist[i].f = 0;
        }
    }

    while (!bfs.empty()) {
        node cur = bfs.front();
        bfs.pop();
        for (auto v : g[cur.u]) {
            if (v != cur.parent and ct[v] != 2) {
                if (ct[v] == 0) dist[v].f = cur.dist + 1;
                else dist[v].s = cur.dist + 1;
                ct[v]++;
                bfs.push({v, cur.u, cur.dist + 1});
            }
        }
    }

    int ans = 0;
    for (auto x : dist) if (x.f <= k and x.s <= k) ans++;
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