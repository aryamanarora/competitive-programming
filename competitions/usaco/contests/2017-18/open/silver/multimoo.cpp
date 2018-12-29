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

struct disjoint_set {
    int n;
    vi parent, size;
    set<int> sets;

    disjoint_set(int N) : n(N), size(N), parent(N) {
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
        sets.insert(v);
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
            sets.erase(b);
        }
    }
};

int get_size(int u, int a, int b, disjoint_set &dsu, vector<vi> &g, vi &val, vector<bool> &visited) {
    u = dsu.find_set(u);
    if (a == b) return 0;
    visited[u] = true;
    int res = dsu.size[u];
    for (auto v : g[u]) {
        if ((val[v] == a or val[v] == b) and !visited[v]) res += get_size(v, a, b, dsu, g, val, visited);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("multimoo.in");
    ofstream cout("multimoo.out");

    int n;
    cin >> n;
    vector<vi> a(n, vi(n));
    disjoint_set dsu(n * n);
    vi val;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            val.pb(a[i][j]);
            dsu.make_set(i * n + j);
        }
    }

    int maxone = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) if (a[i][j] == a[i - 1][j]) dsu.make_union(i * n + j, (i - 1) * n + j);
            if (j > 0) if (a[i][j] == a[i][j - 1]) dsu.make_union(i * n + j, i * n + j - 1);
            if (i < n - 1) if (a[i][j] == a[i + 1][j]) dsu.make_union(i * n + j, (i + 1) * n + j);
            if (j < n - 1) if (a[i][j] == a[i][j + 1]) dsu.make_union(i * n + j, i * n + j + 1);
            maxone = max(maxone, dsu.size[dsu.find_set(i * n + j)]);
        }
    }


    vector<vi> g(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // // cerr << i << " " << j << " " << i * n + j << endl;
            if (i < n - 1) if (a[i][j] != a[i + 1][j]) {
                g[dsu.find_set(i * n + j)].pb(dsu.find_set((i + 1) * n + j));
                g[dsu.find_set((i + 1) * n + j)].pb(dsu.find_set(i * n + j));
            }
            if (j < n - 1) if (a[i][j] != a[i][j + 1]) {
                g[dsu.find_set(i * n + j)].pb(dsu.find_set(i * n + j + 1));
                g[dsu.find_set(i * n + j + 1)].pb(dsu.find_set(i * n + j));
            }
        }
    }

    

    set<ii> done;

    int maxtwo = 0;
    for (int i = 0; i < n * n; i++) {
        int iset = dsu.find_set(i);
        if (i / n < n - 1) {
            int j = (i / n + 1) * n + i % n;
            if (val[j] != val[i]) {
                int jset = dsu.find_set(j);
                if (!done.count({iset, jset})) {
                    vector<bool> visited(n * n);
                    int res = get_size(i, val[i], val[j], dsu, g, val, visited);
                    // cerr << "(" << i / n << ", " << i % n << "), (" << j / n << " " << j % n << ") " << val[i] << " " << val[j] << ": " << res << endl;
                    maxtwo = max(maxtwo, res);
                }
                done.insert({iset, jset});
            }
        }
        if (i % n < n - 1) {
            int j = (i / n) * n + i % n + 1;
            if (val[j] != val[i]) {
                int jset = dsu.find_set(j);
                if (!done.count({iset, jset})) {
                    vector<bool> visited(n * n);
                    int res = get_size(i, val[i], val[j], dsu, g, val, visited);
                    // cerr << "(" << i / n << ", " << i % n << "), (" << j / n << " " << j % n << ") " << val[i] << " " << val[j] << ": " << res << endl;
                    maxtwo = max(maxtwo, res);
                }
                done.insert({iset, jset});
            }
        }
    }

    cout << maxone << endl << maxtwo << endl;
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