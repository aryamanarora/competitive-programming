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

    ll n;
    cin >> n;
    n--;
    ll ans = n;
    for (ll i = 2LL; i <= n; i *= 2LL) {
        ans += (n / i) * (i / 2);
        // cout << (i / 2) << ": " << (n / i) << endl;
        // cout << ans << endl;
    }
    cout << ans << endl;
}

/*
1 2 1 4 1 2 1 8 1
1 1 1 1 1 1 1 1 1 9/1 = 9
0 1 0 1 0 1 0 1 0 9/2 = 4
0 0 0 2 0 0 0 2 0 9/4 = 2
0 0 0 0 0 0 0 4 0 9/8 = 1
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