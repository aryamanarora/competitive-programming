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

    ifstream cin("perimeter.in");
    ofstream cout("perimeter.out");

    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    disjoint_set dsu(n * n);
    for (int i = 0; i < n * n; i++) if (a[i / n][i % n] == '#') dsu.make_set(i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '.') continue;
            if (i > 0) if (a[i - 1][j] == '#') dsu.make_union(i * n + j, i * n + j - n);
            if (i < n - 1) if (a[i + 1][j] == '#') dsu.make_union(i * n + j, i * n + j + n);
            if (j > 0) if (a[i][j - 1] == '#') dsu.make_union(i * n + j, i * n + j - 1);
            if (j < n - 1) if (a[i][j + 1] == '#') dsu.make_union(i * n + j, i * n + j + 1);
        }
    }

    vi anss; int sz = 0;
    for (int i = 0; i < n * n; i++) {
        if (dsu.size[i] > sz) {
            anss.clear();
            sz = dsu.size[i];
            anss.pb(i);
        }
        else if (dsu.size[i] == sz) {
            anss.pb(i);
        }
    }

    /*
    for (auto &x : perim) {
        for (auto &y : x) cerr << y << " ";
        cerr << endl;
    }
    */

    vi perim(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#') continue;
            vi add;
            if (i > 0) if (a[i - 1][j] == '#') add.pb(dsu.find_set(i * n + j - n));
            if (i < n - 1) if (a[i + 1][j] == '#') add.pb(dsu.find_set(i * n + j + n));
            if (j > 0) if (a[i][j - 1] == '#') add.pb(dsu.find_set(i * n + j - 1));
            if (j < n - 1) if (a[i][j + 1] == '#') add.pb(dsu.find_set(i * n + j + 1));
            for (auto &x : add) perim[x]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // cerr << dsu.find_set(i * n + j) << " ";
            if (a[i][j] == '.') continue;
            if (i == 0) perim[dsu.find_set(i * n + j)]++;
            if (i == n - 1) perim[dsu.find_set(i * n + j)]++;
            if (j == 0) perim[dsu.find_set(i * n + j)]++;
            if (j == n - 1) perim[dsu.find_set(i * n + j)]++;
        }
        // cerr << endl;
    }

    int p = perim[anss[0]];
    for (auto &x : anss) {
        // cerr << perim[x] << " ";
        p = min(p, perim[x]);
    }
    // cerr << endl;

    cout << sz << " " << p << endl;
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