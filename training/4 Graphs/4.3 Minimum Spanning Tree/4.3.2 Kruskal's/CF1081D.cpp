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
    void make_set(int v, bool need) {
        parent[v] = v;
        size[v] = (need ? 1 : 0);
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

    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> need(n); int x; 
    for (int i = 0; i < k; i++) {
        cin >> x;
        x--;
        need[x] = true;
    }

    vector<pair<int, ii>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].s.f >> edges[i].s.s >> edges[i].f;
        edges[i].s.f--;
        edges[i].s.s--;
    }
    sort(edges.begin(), edges.end());

    disjoint_set dsu(n);
    for (int i = 0; i < n; i++) dsu.make_set(i, need[i]);

    // Kruskal's
    need[x] = false;
    int ans = 0;
    for (auto e : edges) {
        if (dsu.size[dsu.find_set(x)] == k) break;
        if (dsu.find_set(e.s.f) != dsu.find_set(e.s.s)) {
            dsu.make_union(e.s.f, e.s.s);
        }
        ans = e.f;
    }

    for (int i = 0; i < k; i++) cout << ans << " ";
    cout << endl;
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