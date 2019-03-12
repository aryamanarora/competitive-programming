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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d;
    cin >> n >> m >> d;
    vii spec;
    vii edges;
    for (int i, u, v; i < m; i++) {
        cin >> u >> v, u--, v--;
        if (u == 0 or v == 0) spec.pb({u, v});
        else edges.pb({u, v});
    }

    if (spec.size() < d) {
        cout << "NO" << endl;
        return 0;
    }

    disjoint_set dsu(n);
    for (int i = 0; i < n; i++) dsu.make_set(i);

    vii ans;
    for (auto &[u, v] : edges) {
        if (dsu.find_set(u) != dsu.find_set(v)) {
            dsu.make_union(u, v);
        }
    }

    for (auto &[u, v] : spec) {
        if (dsu.find_set(u) != dsu.find_set(v)) {
            ans.pb({u, v});
            dsu.make_union(u, v);
        }
    }

    if (ans.size() > d) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) dsu.make_set(i);

    vii anss;
    for (auto &[u, v] : ans) {
        anss.pb({u, v});
        dsu.make_union(u, v);
        d--;
    }

    for (auto &[u, v] : spec) {
        if (d == 0) break;
        if (dsu.find_set(u) != dsu.find_set(v)) {
            anss.pb({u, v});
            dsu.make_union(u, v);
            d--;
        }
    }

    for (auto &[u, v] : edges) {
        if (dsu.find_set(u) != dsu.find_set(v)) {
            anss.pb({u, v});
            dsu.make_union(u, v);
            d--;
        }
    }

    cout << "YES" << endl;
    for (auto &[u, v] : anss) cout << u + 1 << " " << v + 1 << '\n';
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