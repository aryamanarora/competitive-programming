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

ll calc(ll b, ll p, ll k) {
    cout << b << " " << p << ":\n";
    vector<vl> dp(k + 1, vl(p + 1));
    dp[0][p] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= p; j++) {
            if (dp[i][j] == 0) continue;
            for (int l = 0; l <= j; l++) {
                dp[i + 1][l] = addmod(dp[i + 1][l], divmod(dp[i][j], j + 1));
            }
        }
    }
    
    for (auto &x : dp) {
        for (auto &y : x) cout << y << " ";
        cout << endl;
    }
    
    ll res = 0;
    for (int i = 0; i <= p; i++) res = addmod(res, mulmod(dp[k][i], powmod(b, i)));
    cout << res << endl;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i) continue;
        ll ct = 0;
        while (n % i == 0) ct++, n /= i;
        ans = mulmod(ans, calc(i, ct, k));
    }
    if (n != 1) ans = mulmod(ans, calc(n, 1, k));
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