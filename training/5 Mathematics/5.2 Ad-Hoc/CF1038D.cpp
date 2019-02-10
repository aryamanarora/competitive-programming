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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi a(n); for (auto &x : a) cin >> x;
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    int mini = *min_element(a.begin(), a.end()), maxi = *max_element(a.begin(), a.end());
    
    ll ans = 0;
    if (mini <= 0 and maxi >= 0) for (auto &x : a) ans += abs(x);
    else if (maxi < 0) {
        ans += 2 * maxi;
        for (auto &x : a) ans -= x;
    }
    else if (mini > 0) {
        ans -= 2 * mini;
        for (auto &x : a) ans += x;
    }

    cout << ans << endl;
}

/*
USE LONG LONG!!!!
:pray:  :summitosity:
        :fishy15:
        :prodakcin:
        :pusheenosity:
        :arceus:
        :sinxosity:

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