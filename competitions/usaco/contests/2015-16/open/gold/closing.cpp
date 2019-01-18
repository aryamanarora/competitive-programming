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

    ifstream cin("closing.in");
    ofstream cout("closing.out");

    int n, m;
    cin >> n >> m;
    vector<vi> g(n); vector<bool> used(n, false);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v; u--, v--;
        g[u].pb(v); g[v].pb(u);
    }

    vi order(n); for (auto &x : order) {cin >> x; x--;}

    disjoint_set dsu(n);
    for (int i = 0; i < n; i++) dsu.make_set(i);
    int ct = 0;
    vector<bool> ans(n);
    for (auto it = order.rbegin(); it != order.rend(); it++) {
        ct++;
        used[*it] = true;
        for (auto &v : g[*it]) {
            if (used[v]) dsu.make_union(*it, v);
        }
        ans[n - ct] = (dsu.size[dsu.find_set(*it)] == ct);
    }
    
    for (const auto &x : ans) cout << (x ? "YES" : "NO") << endl;
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