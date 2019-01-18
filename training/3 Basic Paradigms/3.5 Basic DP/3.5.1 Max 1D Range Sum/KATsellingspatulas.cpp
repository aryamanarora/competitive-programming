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

void solve(int n) {
    vii dp(1440, {-8, -1});
    for (int i = 0; i < n; i++) {
        int t; double p;
        cin >> t >> p;
        dp[t].f += round(p * 100);
    }

    pair<int, ii> ans = {-100, {-1, -1}};
    for (int i = 0; i < 1440; i++) {
        dp[i].s = i;
        if (i > 0) dp[i] = max(dp[i], {dp[i].f + dp[i - 1].f , dp[i - 1].s});
        if (dp[i].f > ans.f) {
            ans = {dp[i].f, {dp[i].s, i}};
        }
        else if (dp[i].f == ans.f) {
            if (i - dp[i].s < ans.s.s - ans.s.f) {
                ans = {dp[i].f, {dp[i].s, i}};
            }
            else if (i - dp[i].s == ans.s.s - ans.s.f) {
                if (dp[i].s < ans.s.f) {
                    ans = {dp[i].f, {dp[i].s, i}};
                }
            }
        }
    }

    if (ans.f > 0.0) {
        cout << fixed << setprecision(2) << static_cast<double>(ans.f) / 100.0 << " ";
        cout << ans.s.f << " " << ans.s.s << endl;
    }
    else cout << "no profit" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        solve(n);
    }
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