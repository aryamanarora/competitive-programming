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

    ll n;
    cin >> n;

    vl dp(30);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 20; i++) {
        dp[i] = dp[i - 1] * 20;
    }

    auto calc = [&](ll val) {
        ll res = 0, cur = 0;
        for (ll i = 19; i >= 0; i--) {
            cout << val << endl;
            if (pow(10LL, i) <= val) {
                res += dp[i] * val / static_cast<ll>(pow(10, i));
                res += cur * val;
                if (val >= 2 * pow(10, i)) res += pow(10, i);
                else cur++;
                val %= static_cast<ll>(pow(10LL, i));
            }
        }
        return res;
    };

    ll one = 0;
    for (int i = 1; i <= n; i++) {
        int c = i;
        while (c > 0) {
            one += (c % 10 == 1);
            c /= 10;
        }
    }
    cout << one << endl;
    cout << calc(n + 1) << endl;
}

/*
USE LONG LONG!!!!

205
100->5

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