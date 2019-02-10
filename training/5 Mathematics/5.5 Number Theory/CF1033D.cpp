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

const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vl a(n); for (auto &x : a) cin >> x;
    map<ll, int> ct;
    vector<bool> factorized(n, true);
    for (int i = 0; i < n; i++) {
        ll x = a[i];
        ll fourth = sqrt(sqrt(x)), third = pow(x, 1.0 / 3.0), square = sqrt(x);
        if (fourth * fourth * fourth * fourth == x) ct[fourth] += 4;
        else if (third * third * third == x) ct[third] += 3;
        else if (square * square == x) ct[square] += 2;
        else factorized[i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) continue;
            ll x = gcd(a[i], a[j]);
            if (x != 1) {
                if (!factorized[i]) {
                    ct[x]++;
                    ct[a[i] / x]++;
                }
                if (!factorized[j]) {
                    ct[x]++;
                    ct[a[j] / x]++;
                }
                factorized[j] = factorized[i] = true;
                break;
            }
        }
    }

    ll ans = 1;
    for (auto &x : ct) {
        // cout << x.f << " " << x.s << endl;
        ans *= (x.s + 1);
        ans %= MOD;
    }
    for (const auto &x : factorized) {
        if (!x) {
            ans *= 4;
            ans %= MOD;
        }
    }
    cout << ans << endl;
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