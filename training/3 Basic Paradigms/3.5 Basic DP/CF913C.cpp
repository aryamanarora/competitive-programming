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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, l;
    cin >> n >> l;
    vl a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) a[i] = min(a[i], a[i - 1] * 2);
    // for (auto x : a) cout << x << " ";
    // cout << endl;

    ll ans = numeric_limits<ll>::max(), cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll req = l / static_cast<ll>(pow(2, i));
        cur += req * a[i];
        l -= req * static_cast<ll>(pow(2, i));
        ans = min(ans, cur + (l > 0) * a[i]);
        // cout << i << " " << req << ": " << cur << endl;
    }

    cout << ans << endl;
}

/*
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