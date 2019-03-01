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
    vector<vi> sets;

    disjoint_set(int N) : n(N), size(N), parent(N), sets(N) {
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
        sets[v].pb(v);
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
            sets[a].insert(sets[a].end(), sets[b].begin(), sets[b].end());
            size[b] = 0;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    disjoint_set dsu(n);
    for (int i = 0; i < n; i++) dsu.make_set(i);

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        dsu.make_union(u, v);
    }

    int head = dsu.find_set(0);
    for (auto &x : dsu.sets[head]) cout << x + 1 << " ";
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