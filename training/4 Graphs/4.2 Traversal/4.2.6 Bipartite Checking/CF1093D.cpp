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

const ll MOD = 998244353;
const int MAX = 300005;

struct disjoint_set {
    int n;
    vi parent, size;

    disjoint_set(int N) : n(N), size(N), parent(N) {
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_union(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (b != a) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            size[b] = 0;
        }
    }
};

vl pow2(MAX);

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vi> g(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    // connected components
    disjoint_set dsu(n);
    for (int i = 0; i < n; i++) dsu.make_set(i);
    for (int u = 0; u < n; u++) {
        for (auto v : g[u]) dsu.make_union(u, v);
    }

    // bipartite check with BFS for each component
    bool bipartite = true;
    vi colour(n, -1);
    queue<int> bfs;
    for (int u = 0; u < n; u++) {
        if (dsu.size[u] != 0) {
            bfs.push(u); // one node from each component
            colour[u] = 0;
        }
    }
    while (!bfs.empty()) {
        int u = bfs.front(); bfs.pop();
        for (auto v : g[u]) {
            if (colour[v] == -1) {
                colour[v] = 1 - colour[u];
                bfs.push(v);
            }
            else if (colour[v] == colour[u]) {
                bipartite = false;
                break;
            }
        }
        if (!bipartite) break;
    }

    /*
    for (auto x : colour) cout << x << " ";
    cout << endl;
    */

    if (!bipartite) {
        cout << 0 << endl;
        return;
    }

    // # of each colour for each component
    vi cta(n, 0), ctb(n, 0);
    for (int i = 0; i < n; i++) {
        if (colour[i] == 0) cta[dsu.find_set(i)]++;
        else ctb[dsu.find_set(i)]++;
    }

    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (cta[i] + ctb[i] != 0) ans *= ((pow2[cta[i]] + pow2[ctb[i]]) % MOD);
        ans %= MOD;
    }

    /*
    for (auto x : cta) cout << x << " ";
    cout << endl;
    for (auto x : ctb) cout << x << " ";
    cout << endl;
    */

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // precalculate powers of 2
    pow2[0] = 1;
    for (int i = 1; i < MAX; i++) pow2[i] = ((pow2[i - 1] * 2) % MOD);

    int t;
    cin >> t;
    while (t--) solve();
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