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

    ifstream cin("countcross.in");
    ofstream cout("countcross.out");

    int n, k, r;
    cin >> n >> k >> r;

    sii roads;
    for (int i = 0; i < r; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        roads.insert({a * n + b, c * n + d});
    }
    
    disjoint_set dsu(n * n);
    for (int i = 0; i < n * n; i++) dsu.make_set(i);

    vii cows(k);
    for (auto &x : cows) {
        cin >> x.f >> x.s;
        x.f--; x.s--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c = i * n + j;
            if (i > 0) {
                int r = (i - 1) * n + j;
                if (!roads.count({c, r}) and !roads.count({r, c})) dsu.make_union(c, r);
            }
            if (j > 0) {
                int r = i * n + (j - 1);
                if (!roads.count({c, r}) and !roads.count({r, c})) dsu.make_union(c, r);
            }
            if (i < n - 1) {
                int r = (i + 1) * n + j;
                if (!roads.count({c, r}) and !roads.count({r, c})) dsu.make_union(c, r);
            }
            if (j < n - 1) {
                int r = i * n + j + 1;
                if (!roads.count({c, r}) and !roads.count({r, c})) dsu.make_union(c, r);
            }
        }
    }

    int ans = 0;
    vi com(k);
    int ct = 0;
    for (auto &x : cows) {
        com[ct] = dsu.find_set(x.f * n + x.s);
        ct++;
    }
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (com[i] != com[j]) ans++;
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