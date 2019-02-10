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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vl ct(n), cost(n);
    for (auto &x : ct) cin >> x;
    for (auto &x : cost) cin >> x;

    sii dishes;
    for (int i = 0; i < n; i++) dishes.insert({cost[i], i});

    for (ll i = 0, t, d; i < m; i++) {
        cin >> t >> d, t--;
        ll ans = 0;
        while (d > 0) {
            if (ct[t] > 0) {
                if (d >= ct[t]) {
                    ans += (ct[t] * cost[t]);
                    d -= ct[t];
                    ct[t] = 0;
                    dishes.erase({cost[t], t});
                }
                else {
                    ans += (d * cost[t]);
                    ct[t] -= d;
                    d = 0;
                }
            }
            else {
                if (dishes.empty()) {
                    ans = 0;
                    break;
                }
                ll use = min(d, ct[dishes.begin()->s]);
                ans += use * dishes.begin()->f;
                d -= use;
                ct[dishes.begin()->s] -= use;
                if (ct[dishes.begin()->s] == 0) dishes.erase(dishes.begin());
            }
        }
        cout << ans << endl;
        // for (auto &x : ct) cout << x << " ";
        // cout << endl;
    }
}

/*
USE LONG LONG!!!!

:pray: :fishy15:
:pray: :summitosity:

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