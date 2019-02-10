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
    void add(int a, int v) {
        for (; a <= n; a += least_significant_one(a)) freq[a] += v;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ifstream cin("sort.in");
    // ofstream cout("sort.out");

    int n, m;
    cin >> n >> m;
    vector<vi> g(n);
    for (int i = 0; i < m; i++) {
        int k, last = -1;
        cin >> k;
        for (int i = 0, j; i < k; i++) {
            cin >> j;
            j--;
            if (last != -1) g[last].pb(j);
            last = j;
        }
    }

    vi order; vector<bool> vis(n, false);
    function<void(int)> toposort = [&](int u) {
        // cout << u << endl;
        vis[u] = true;
        for (auto &v : g[u]) {
            if (!vis[v]) toposort(v);
        }
        order.pb(u);
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) toposort(i);
    }

    reverse(order.begin(), order.end());
    for (auto &x : order) cout << x + 1 << " ";
    cout << endl;
}

/*
1 8 5 3 2
1 2 3 5 8
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