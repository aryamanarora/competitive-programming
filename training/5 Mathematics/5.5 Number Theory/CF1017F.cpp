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

const ll MOD = pow(2LL, 32LL);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    vl val(n + 1), res(n + 1);
    iota(val.begin(), val.end(), 0LL);
    for (int i = 2; i <= n; i++) {
        if (val[i] == i) {
            res[i] += (a * ((((i * i) % MOD) * i) % MOD)) % MOD;
            res[i] += (b * ((i * i) % MOD)) % MOD;
            res[i] += (c * i) % MOD;
            res[i] %= MOD;
            res[i] += d;
            res[i] %= MOD;
        }
        else continue;
        for (int j = 2 * i; j <= n; j += i) {
            while (val[j] % i == 0) {
                val[j] /= i;
                res[j] += res[i];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (val[i])
        // cout << res[i] << " ";
        res[i] = (res[i - 1] + res[i]) % MOD;
    }
    // cout << endl;
    cout << res[n] << endl;
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