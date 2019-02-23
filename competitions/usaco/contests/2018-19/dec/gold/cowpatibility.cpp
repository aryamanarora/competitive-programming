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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("cowpatibility.in");
    ofstream cout("cowpatibility.out");

    map<array<int, 5>, int> ct[6];

    ll n;
    cin >> n;

    array<int, 5> x, y;
    for (int i = 0; i < n; i++) {
        for (auto &y : x) cin >> y;
        sort(x.begin(), x.end());
        y = x;
        for (int j = 1; j < 32; j++) {
            for (int k = 0; k < 5; k++) {
                if ((1 << k) & j) y[k] = x[k];
                else y[k] = 0;
            }
            sort(y.begin(), y.end());
            ct[__builtin_popcount(j)][y]++;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= 5; i++) {
        for (auto &y : ct[i]) {
            if (i % 2) ans += (y.s * (y.s - 1LL)) / 2LL;
            else ans -= (y.s * (y.s - 1LL)) / 2LL;
            // cerr << (y.s * (y.s - 1)) / 2 << endl;
        }
        // cerr << ans << endl;
        // cerr << endl;
    }

    ans = (n * (n - 1)) / 2 - ans;
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

