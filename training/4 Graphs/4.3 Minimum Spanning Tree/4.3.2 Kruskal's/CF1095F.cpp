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

    int n, m;
    cin >> n >> m;
    vl val(n); int minval = 0;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        if (val[i] < val[minval]) minval = i;
    }

    vector<pair<ll, ii>> edges(m);
    for (auto &[w, g] : edges) {
        cin >> g.f >> g.s >> w;
        g.f--; g.s--;
    }
    for (int i = 0; i < n; i++) if (i != minval) edges.pb({val[i] + val[minval], {minval, i}});
    sort(edges.begin(), edges.end());

    // Kruskal's
    disjoint_set dsu(n);
    for (int i = 0; i < n; i++) dsu.make_set(i);
    ll ans = 0;
    for (auto [w, g] : edges) {
        if (dsu.find_set(g.f) != dsu.find_set(g.s)) {
            // cout << g.f << " " << g.s << " " << w << endl;
            ans += w;
            dsu.make_union(g.f, g.s);
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