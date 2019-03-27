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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vi a(n); for (auto &x : a) cin >> x, x--;
    vi pos(n); for (int i = 0; i < n; i++) pos[a[i]] = i;

    vector<si> g(n);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, u--, v--;
        g[u].insert(v);
    }

    si cur = {a.back()};
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        // cout << a[i] + 1 << ": ";
        bool skipped = true;
        for (auto &x : cur) {
            if (!g[a[i]].count(x)) {
                skipped = false;
                break;
            }
        }
        if (skipped) ans++;
        else cur.insert(a[i]);
        // for (auto &x : cur) cout << x + 1 << " ";
        // cout << endl;
    }

    cout << ans << endl;
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