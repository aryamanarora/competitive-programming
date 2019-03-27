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

template<typename T>
T least_significant_one(T x) {
    return (x & (-x));
}

struct fenwick_tree {
    int n;
    vl freq;
    fenwick_tree(int N) : n(N), freq(N + 1, 0) {};
    ll sum(int a) {
        ll res = 0;
        for (; a; a -= least_significant_one(a)) res += freq[a];
        return res;
    }
    ll sum(int a, int b) {
        return (sum(b) - (a == 0 ? 0 : sum(a - 1)));
    }
    void add(int a, int v) {
        for (; a <= n; a += least_significant_one(a)) {
            freq[a] += v;
        }
    }
};

int ct = 0;
void dfs(int u, int p, vi &start, vi &end, vector<vi> &g) {
    start[u] = ct++;
    for (auto &v : g[u]) {
        if (v == p) continue;
        dfs(v, u, start, end, g);
    }
    end[u] = ct - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vi val(n); for (auto &x : val) cin >> x;

    vector<vi> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vi start(n), end(n);
    dfs(0, -1, start, end, g);

    fenwick_tree ft(ct);
    for (int i = 0; i < n; i++) {
        ft.add(start[i] + 1, val[i]);
    }

    while (q--) {
        int qq; cin >> qq;
        if (qq == 1) {
            int s, x; cin >> s >> x;
            s--;
            ft.add(start[s] + 1, x - val[s]);
            val[s] = x;
        }
        else {
            int s; cin >> s;
            s--;
            cout << ft.sum(start[s] + 1, end[s] + 1) << endl;
        }
    }
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