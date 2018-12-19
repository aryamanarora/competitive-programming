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

const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vl> dp(k + 1, vl(n + 1, 0));
    dp[0][1] = m;
    
    // n is number of bricks
    // k is number different to the left
    for (int K = 0; K <= k; K++) {
        for (int N = 1; N <= n; N++) {
            // cout << K << " " << N << endl;
            if (K == 0 and N == 1) continue;
            dp[K][N] += dp[K][N - 1];
            dp[K][N] %= MOD;
            if (K > 0) {
                dp[K][N] += (m - 1) * dp[K - 1][N - 1];
                dp[K][N] %= MOD;
            }
        }
    }

    /*
    for (auto x : dp) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
    */

    cout << dp[k][n] << endl;
}

/*
3 2 2

0 2 2 2
0 0 2 4
0 0 0 2

aab abb baa bba

aabb abbb baa bbaa aaab bbba


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