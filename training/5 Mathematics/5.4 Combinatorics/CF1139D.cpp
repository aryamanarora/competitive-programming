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

ll modinv(ll x, ll y) {
    return (x * modpow(y, MOD - 2)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m;
    cin >> m;

    vi val(m + 1); iota(val.begin(), val.end(), 0);
    vi ct(m + 1, 1);
    for (int i = 1; i * i <= m; i++) {
        if (val[i] == 1) continue;
        for (int j = 2 * i; j <= m; j += i) {
            int c = 0;
            while (val[j] % i == 0) {
                val[j] /= i;
                c++;
            }
            if (c != 0) ct[j] *= (c + 1);
        }
    }

    for (int i = 0; i <= m; i++) {
        if (val[i] != 1) ct[i] = 1;
        else ct[i]--;
    }

    ll ans = 0;
    // (1 / n) * ct * (n / (n - 1)^2)
    ll d = modinv(2 * m, (m - 1) * (m - 1));
    for (int i = 2; i <= m; i++) {
        ll res = modinv(ct[i], m);
        res = (res * d) % MOD;
        cout << i << " " << ct[i] << " " << res << endl;
        ans += res;
    }
    cout << endl;

    cout << ans << endl;
}

/*
2
1 -> 1*1
2 -> 2*1/2 + 3*1/4 ...
4
2 -> 1/4 + 2/4^2 + 3/4^3 + ...
3 -> 1/4 + 2/4^2 + 3/4^3 + ...
4 -> 2(1/4 + 2/4^2 + 3/4^3 + ...)
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