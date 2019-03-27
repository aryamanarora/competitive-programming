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

const ll MOD = 1e9 + 7;

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

ll modpow(ll x, ll y) { 
    ll res = 1;
    while (y) {
        if (y % 2) res = (res * x) % MOD;
        y /= 2;
        x = (x * x) % MOD;
    }
    return res; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    disjoint_set dsu(n);
    for (int i = 0; i < n; i++) dsu.make_set(i);
    for (int i = 0, u, v, x; i < n - 1; i++) {
        cin >> u >> v >> x, u--, v--;
        if (x == 0) dsu.make_union(u, v);
    }

    ll ans = modpow(n, k);
    for (auto &x : dsu.size) {
        ans = (ans - modpow(x, k) + MOD) % MOD;
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