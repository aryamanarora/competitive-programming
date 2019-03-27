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
    set<ii> cur;
    vi a(n + 1);
    for (int i = 1, maxi = 0; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= maxi) {
            cur.insert({a[i], i});
            maxi = a[i];
        }
    }

    for (int i = 0, j; i < m; i++) {
        cin >> j;
        auto it = cur.lower_bound({j, 0});
        if (it == cur.end() or cur.empty()) cout << 0 << ' ';
        else {
            cout << it->s << ' ';
            a[it->s] -= j;
            int maxi = (it == cur.begin() ? 0 : prev(it)->f),
                end = (it == prev(cur.end()) ? n : next(it)->s);
            // cout << maxi << " " << end << endl;
            cur.erase(it);
            for (int k = it->s; k <= end; k++) {
                if (a[k] >= maxi) {
                    cur.insert({a[k], k});
                    maxi = a[k];
                }
            }
        }
    }
    cout << '\n';
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