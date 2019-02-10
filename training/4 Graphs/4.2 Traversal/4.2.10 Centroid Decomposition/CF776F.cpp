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
    vii edges(m);
    for (auto &x : edges) {
        cin >> x.f >> x.s;
        if (x.f < x.s) swap(x.f, x.s);
    }
    edges.pb({n, 1});
    sort(edges.rbegin(), edges.rend());
    vii events(m * 2 + 2);
    for (int i = 0; i <= m; i++) {
        events[i * 2] = {edges[i].f, i + 1};
        events[i * 2 + 1] = {edges[i].s, -i - 1};
    }
    sort(events.rbegin(), events.rend());

    stack<int> st;
    // cout << endl;
    for (auto &x : events) {
        // cout << x.f << " " << x.s << endl;
        if (x.s > 0) {
            if (!st.empty()) {
                int v = st.top();
                g[v].pb(x.s - 1);
                g[x.s - 1].pb(v);
            }
            st.push(x.s - 1);
        }
        else {
            st.pop();
        }
    }
    // cout << endl;

    vi colour(m + 1, -1); vi sz(m, 1); vector<bool> vis(m, false);

    function<void(int, int)> dfs_size = [&](int u, int p) {
        for (auto &v : g[u]) {
            if (v == p) continue;
            dfs_size(v, u);
            sz[u] += sz[v];
        }
    };

    dfs_size(0, -1);

    function<void(int, int, int)> centroid_decomp = [&](int u, int depth, int nn) {
        int maxi = -1;
        for (auto &v : g[u]) {
            if (vis[v]) continue;
            if (maxi == -1) maxi = v;
            else if (sz[maxi] < sz[v]) maxi = v;
        }
        if (maxi == -1) {
            vis[u] = true;
            colour[u] = depth;
            sz[u] = 0;
        }
        else if (sz[maxi] > nn / 2) {
            sz[u] -= sz[maxi];
            sz[maxi] += sz[u];
            centroid_decomp(maxi, depth, nn);
        }
        else {
            vis[u] = true;
            colour[u] = depth;
            sz[u] = 0;
            for (auto &v : g[u]) {
                if (!vis[v]) centroid_decomp(v, depth + 1, sz[v]);
            }
        }
    };

    centroid_decomp(0, 1, m);

    for (auto &x : colour) cout << x << " ";
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