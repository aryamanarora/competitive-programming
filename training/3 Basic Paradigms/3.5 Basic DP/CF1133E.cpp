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

    int n, k;
    cin >> n >> k;
    vi a(n); for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    vi dp(n);
    
    int lo = 0, hi = 0;
    while (lo != n) {
        dp[hi] = max(dp[hi], hi - lo + 1);
        if (hi != n - 1) {
            if (a[hi + 1] - a[lo] <= 5) hi++;
            else if (lo != hi) lo++;
            else lo = (++hi);
        }
        else lo++;
    }

    vector<vi> dp2(n, vi(k, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (j == 0) dp2[i][j] = dp[i];
            else {
                if (i - dp[i] >= 0) dp2[i][j] = max(dp2[i][j], dp[i] + dp2[i - dp[i]][j - 1]);
                dp2[i][j] = max(dp2[i][j], dp2[i][j - 1]);
            }
            if (i > 0) dp2[i][j] = max(dp2[i][j], dp2[i - 1][j]);
        }
    }

    cout << dp2[n - 1][k - 1] << endl;
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