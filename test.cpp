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

const int INF = numeric_limits<int>::max();

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a) cin >> x;
    set<ii> l, r;
    for (int i = 2; i < n; i++) r.insert({a[i], i});

    int ans = 0; ii res;
    for (int i = 0; i < n; i++) {
        if (i < n - 2) {
            if (a[i] + prev(r.end())->f > ans) {
                ans = a[i] + prev(r.end())->f;
                res = {a[i], prev(r.end())->f};
            }
        }
        if (i > 1) {
            if (a[i] + prev(l.end())->f > ans) {
                ans = a[i] + prev(l.end())->f;
                res = {a[i], prev(l.end())->f};
            }
        }
        if (i < n - 2) r.erase({a[i + 2], i + 2});
        if (i > 1) l.insert({a[i - 2], i - 2});
        if (a[i] > ans) {
            ans = a[i];
            res = {a[i], INF};
        }
    }

    cout << min(res.f, res.s) << (max(res.f, res.s) == INF ? "" : to_string(max(res.f, res.s)))  << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
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