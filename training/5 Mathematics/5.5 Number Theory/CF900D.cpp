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

ll modpow(ll x, ll y) { 
    ll res = 1;
    while (y) {
        if (y % 2) res = (res * x) % MOD;
        y /= 2;
        x = (x * x) % MOD;
    }
    return res; 
}

map<int, int> memo = {{1, 1}};
ll calc(ll sum) {
    if (memo.count(sum)) return memo[sum];
    ll ans = modpow(2, sum - 1) - 1;
    for (int i = 2; i * i <= sum; i++) {
        if (sum % i == 0) {
            ans = (ans + MOD - calc(sum / i)) % MOD;
            if (i * i != sum) ans = (ans + MOD - calc(sum / (sum / i))) % MOD;
        }
    }
    return memo[sum] = (ans % MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y;
    cin >> x >> y;
    if (y % x) {
        cout << 0 << endl;
        return 0;
    }

    cout << calc(y / x) << endl;
}

/*
USE LONG LONG!!!!

0 1 2 3 4 5 6
1 1 2 4 8 16

4
1 1 1 1 : 1
2 1 1   : 1
1 2 1   : 1
1 1 2   : 1
2 2     : 2
3 1     : 1
1 3     : 1
4       : 4

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