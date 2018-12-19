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

const ll INF = numeric_limits<ll>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi cost(n);
    for (int i = 0; i < n; i++) cin >> cost[i];
    vector<pair<string, string>> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].f;
        s[i].s = s[i].f;
        reverse(s[i].s.begin(), s[i].s.end());
    }

    vector<pair<ll, ll>> dp(n, {INF, INF});
    dp[0].f = 0;
    dp[0].s = cost[0];
    for (int i = 1; i < n; i++) {
        if (dp[i - 1].f != INF) {
            if (s[i].f >= s[i - 1].f) dp[i].f = min(dp[i].f, dp[i - 1].f);
            if (s[i].s >= s[i - 1].f) dp[i].s = min(dp[i].s, dp[i - 1].f + cost[i]);
        }
        if (dp[i - 1].s != INF) {
            if (s[i].f >= s[i - 1].s) dp[i].f = min(dp[i].f, dp[i - 1].s);
            if (s[i].s >= s[i - 1].s) dp[i].s = min(dp[i].s, dp[i - 1].s + cost[i]);
        }

        if (dp[i].f == INF and dp[i].s == INF) {
            cout << -1 << endl;
            return 0;
        }
    }

    // for (auto x : s) cout << x.f << " " << x.s << endl;
    // for (auto x : dp) cout << x.f << " " << x.s << endl;

    cout << min(dp[n - 1].f, dp[n - 1].s) << endl;
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