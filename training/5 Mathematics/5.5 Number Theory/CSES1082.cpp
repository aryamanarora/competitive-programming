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

const ll MOD = 1e9 + 7;

ll mulmod(ll a, ll b) {
    ll res = 0;
    a %= MOD;
    while (b > 0) {
        if (b % 2) res = (res + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return res % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll ans = 0;
    for (ll i = 1; i * i <= n; i++) {
        ll ct = n / i;
        ans += (ct - i + 1) * i;
        ans %= MOD;
        ct--;
        ll start = i + 1, end = ct + 1;
        if (start <= end) {
            ans = (ans + (end % 2 ? mulmod(end, (end + 1) / 2) : mulmod(end / 2, end + 1))) % MOD;
            ans = (ans + MOD - (start % 2 ? mulmod(start, (start- 1) / 2) : mulmod(start / 2, start - 1))) % MOD;
        }
    }

    cout << ans << endl;
}

/*
USE LONG LONG!!!!

1 1 1 1 1 1 1
 (2)  2   2

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