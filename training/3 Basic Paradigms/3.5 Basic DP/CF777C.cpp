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

    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (auto &x : a) for (auto &y : x) cin >> y;

    vector<vi> dp(n, vi(m, 1));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) if (a[i][j] >= a[i - 1][j]) dp[i][j] = dp[i - 1][j] + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) dp[i][0] = max(dp[i][0], dp[i][j]);
    }

    int q;
    cin >> q;
    while (q--) {
        int t, b;
        cin >> t >> b;
        t -= 2; b--;
        if (dp[b][0] >= b - t) cout << "Yes" << endl;
        else cout << "No" << endl;
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