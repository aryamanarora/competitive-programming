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

const int MAX = 32;

ll choose[MAX][MAX] = {1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;

    for (int n = 0; n < MAX; n++) {
        for (int k = 0; k < MAX; k++) {
            if (n > 0 and k > 0) choose[n][k] += choose[n - 1][k] + choose[n - 1][k - 1];
            else if (n > 0) choose[n][k] += choose[n - 1][k];
        }
    }

    ll ans = 0;
    for (int k = 4; k <= n and k < t; k++) {
        if (t - k > m) continue;
        ans += choose[n][k] * choose[m][t - k];
        // cout << k << " boys, " << t - k << " girl(s): " << choose[n][k] * choose[m][t - k] << endl;
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