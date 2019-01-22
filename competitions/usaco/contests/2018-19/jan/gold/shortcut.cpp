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

const int INF = numeric_limits<int>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("shortcut.in");
    ofstream cout("shortcut.out");

    int n, m, t;
    cin >> n >> m >> t;
    vi c(n); for (auto &x : c) cin >> x;
    vector<vii> g(n);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    vl dist(n, INF); vi p(n, -1);
    dist[0] = 0;

    function<void()> dijkstra = [&]() {
        set<pair<ll, int>> q;
        q.insert({0, 0});
        while (!q.empty()) {
            int u = q.begin()->s;
            q.erase(q.begin());

            for (auto &e : g[u]) {
                int v = e.f, d = e.s;
                if (dist[u] + d < dist[v]) {
                    q.erase({dist[v], v});
                    dist[v] = dist[u] + d;
                    p[v] = u;
                    q.insert({dist[v], v});
                }
                else if (dist[u] + d == dist[v]) {
                    p[v] = min(p[v], u);
                }
            }
        }
    };

    dijkstra();

    vector<vi> g_tree(n);
    for (int i = 1; i < n; i++) {
        g_tree[p[i]].pb(i);
    }

    vi ct(n);

    function<void(int)> dfs = [&](int u) {
        ct[u] += c[u];
        for (auto &v : g_tree[u]) {
            dfs(v);
            ct[u] += ct[v];
        }
    };

    dfs(0);

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (t < dist[i]) {
            ans = max(ans, (dist[i] - t) * ct[i]);
        }
    }
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