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

const int BITS = 60;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    vl ct(BITS);
    for (ll i = 0, j; i < n; i++) {
        cin >> j;
        for (ll k = 0; k < BITS; k++) {
            if ((1LL << k) & j) ct[k]++;
        }
    }

    ll res = 0, ans = 0;
    for (ll i = BITS - 1; i >= 0; i--) {
        if (ct[i] < n - ct[i] and res + (1LL << i) <= k) {
            res += (1LL << i);
            ans += (n - ct[i]) * (1LL << i);
        }
        else ans += ct[i] * (1LL << i);
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
/*
7 4 0 3

1001

0111
0100
0000
0011

0221
4223


dp:


*/