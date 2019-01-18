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

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<char> a(n);
    for (auto &x : a) cin >> x;

    vector<vi> dp(n, vi(n));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == 's') {
            dp[i][n - 1] = (dp[i - 1][n - 1]) % MOD;
            for (int j = n - 2; j >= 0; j--) dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % MOD;
        }
        else if (a[i - 1] == 'f') {
            for (int j = 1; j < n; j++) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
        }
    }
    
    /*
    for (auto &x : dp) {
        for (auto &y : x) cout << y << " ";
        cout << endl;
    }
    */

    int ans = 0;
    for (auto &x : dp[n - 1]) ans = (ans + x) % MOD;
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