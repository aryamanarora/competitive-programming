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

ll addmod(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}
ll mulmod(ll a, ll b) {
    ll res = 0;
    a %= MOD;
    b %= MOD;
    if (b > a) swap(a, b);
    while (b > 0) {
        if (b % 2) res = (res + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return res;
}
ll powmod(ll a, ll p) {
    ll res = 1;
    a %= MOD;
    while (p > 0) {
        if (p % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        p /= 2;
    }
    return res;
}
vl inv(10000, -1);
ll divmod(ll a, ll b) {
    ll res = (inv[b] != -1 ? inv[b] : inv[b] = powmod(b, MOD - 2));
    res = mulmod(res, a);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    map<int, vl> memo;
    auto calc = [&](int m) {
        if (memo.count(m)) return memo[m];
        vector<vl> dp(k + 1, vl(m + 1));
        dp[0][m] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = m; j >= 0; j--) {
                dp[i][j] = divmod(dp[i - 1][j], j + 1);
                if (j < m) dp[i][j] = addmod(dp[i][j], dp[i][j + 1]);
            }
        }
        return (memo[m] = dp[k]);
    };
    
    ll ans = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i) continue;
        int ct = 0;
        while (n % i == 0) ct++, n /= i;
        
        int j = 0; ll res = 0;
        for (auto &x : calc(ct)) {
            res = addmod(res, mulmod(powmod(i, j), x));
            j++;
        }
        ans = mulmod(ans, res);
    }
    if (n != 1) {
        int j = 0; ll res = 0;
        for (auto &x : calc(1)) {
            res = addmod(res, mulmod(powmod(n, j), x));
            j++;
        }
        ans = mulmod(ans, res);
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