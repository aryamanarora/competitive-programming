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

    int n;
    cin >> n;
    vector<pair<string, int>> a(2 * n - 2);
    for (int i = 0; i < 2 * n - 2; i++) {
        cin >> a[i].f;
        a[i].s = i;
    }
    sort(a.begin(), a.end(), [](const auto &a, const auto &b) {
        if (a.f.length() < b.f.length()) return true;
        if (a.f.length() > b.f.length()) return false;
        return a.f < b.f;
    });
    // for (auto x : a) cout << x.f << endl;
    // cout << endl;
    
    vector<pair<vi, vi>> dp(2 * n - 2);
    dp[0].f.pb(-1); dp[0].s.pb(-1);
    dp[1].f.pb(-1); dp[1].s.pb(-1);
    vector<bool> ans(2 * n - 2);
    for (int i = 1; i < n - 1; i++) {
        int shared = max(0, 2 * (i + 1) - n);
        int not_shared = min(i, i + 1 - shared);
        if (shared != 0) {
            if (a[i * 2].f.substr(not_shared) == a[i * 2 + 1].f.substr(0, shared)) {
                // cout << i << " left is pre, right is suf" << endl;
                // left is pre, right is suf
                if (i > 0) {
                    // check if beginnings match
                    // cout << a[i * 2].f.substr(0, i) << " " << a[(i - 1) * 2].f << " " << a[(i - 1) * 2 + 1].f  << endl;
                    if (a[i * 2].f.substr(0, i) == a[(i - 1) * 2].f and dp[(i - 1) * 2].f.size() + dp[(i - 1) * 2].s.size() != 0) dp[i * 2].f.pb((i - 1) * 2);
                    if (a[i * 2].f.substr(0, i) == a[(i - 1) * 2 + 1].f and dp[(i - 1) * 2 + 1].f.size() + dp[(i - 1) * 2 + 1].s.size() != 0) dp[i * 2].f.pb((i - 1) * 2 + 1);

                    // check if ends match
                    // cout << a[i * 2 + 1].f.substr(1) << " " << a[(i - 1) * 2].f << " " << a[(i - 1) * 2 + 1].f  << endl;
                    if (a[i * 2 + 1].f.substr(1) == a[(i - 1) * 2].f and dp[(i - 1) * 2].f.size() + dp[(i - 1) * 2].s.size() != 0) dp[i * 2 + 1].s.pb((i - 1) * 2);
                    if (a[i * 2 + 1].f.substr(1) == a[(i - 1) * 2 + 1].f and dp[(i - 1) * 2 + 1].f.size() + dp[(i - 1) * 2 + 1].s.size() != 0) dp[i * 2 + 1].s.pb((i - 1) * 2 + 1);
                }
            }
            if (a[i * 2].f.substr(0, shared) == a[i * 2 + 1].f.substr(not_shared)) {
                // cout << i << " left is suf, right is pre" << endl;
                // left is suf, right is pre
                if (i > 0) {
                    // check if ends match
                    // cout << a[i * 2].f.substr(1) << " " << a[(i - 1) * 2].f << " " << a[(i - 1) * 2 + 1].f  << endl;
                    if (a[i * 2].f.substr(1) == a[(i - 1) * 2].f and dp[(i - 1) * 2].f.size() + dp[(i - 1) * 2].s.size() != 0) dp[i * 2].s.pb((i - 1) * 2);
                    if (a[i * 2].f.substr(1) == a[(i - 1) * 2 + 1].f and dp[(i - 1) * 2 + 1].f.size() + dp[(i - 1) * 2 + 1].s.size() != 0) dp[i * 2].s.pb((i - 1) * 2 + 1);

                    // check if beginnings match
                    // cout << a[i * 2 + 1].f.substr(0, i) << " " << a[(i - 1) * 2].f << " " << a[(i - 1) * 2 + 1].f  << endl;
                    if (a[i * 2 + 1].f.substr(0, i) == a[(i - 1) * 2].f and dp[(i - 1) * 2].f.size() + dp[(i - 1) * 2].s.size() != 0) dp[i * 2 + 1].f.pb((i - 1) * 2);
                    if (a[i * 2 + 1].f.substr(0, i)  == a[(i - 1) * 2 + 1].f and dp[(i - 1) * 2 + 1].f.size() + dp[(i - 1) * 2 + 1].s.size() != 0) dp[i * 2 + 1].f.pb((i - 1) * 2 + 1);
                }
            }
        }
        else {
            if (i > 0) {
                // check if beginnings match
                if (a[i * 2].f.substr(0, i) == a[(i - 1) * 2].f and dp[(i - 1) * 2].f.size() + dp[(i - 1) * 2].s.size() != 0) dp[i * 2].f.pb((i - 1) * 2);
                if (a[i * 2].f.substr(0, i) == a[(i - 1) * 2 + 1].f and dp[(i - 1) * 2 + 1].f.size() + dp[(i - 1) * 2 + 1].s.size() != 0) dp[i * 2].f.pb((i - 1) * 2 + 1);
                // check if ends match
                if (a[i * 2 + 1].f.substr(1) == a[(i - 1) * 2].f and dp[(i - 1) * 2].f.size() + dp[(i - 1) * 2].s.size() != 0) dp[i * 2 + 1].s.pb((i - 1) * 2);
                if (a[i * 2 + 1].f.substr(1) == a[(i - 1) * 2 + 1].f and dp[(i - 1) * 2 + 1].f.size() + dp[(i - 1) * 2 + 1].s.size() != 0) dp[i * 2 + 1].s.pb((i - 1) * 2 + 1);

                // check if ends match
                if (a[i * 2].f.substr(1) == a[(i - 1) * 2].f and dp[(i - 1) * 2].f.size() + dp[(i - 1) * 2].s.size() != 0) dp[i * 2].s.pb((i - 1) * 2);
                if (a[i * 2].f.substr(1) == a[(i - 1) * 2 + 1].f and dp[(i - 1) * 2 + 1].f.size() + dp[(i - 1) * 2 + 1].s.size() != 0) dp[i * 2].s.pb((i - 1) * 2 + 1);

                // check if beginnings match
                if (a[i * 2 + 1].f.substr(0, i) == a[(i - 1) * 2].f and dp[(i - 1) * 2].f.size() + dp[(i - 1) * 2].s.size() != 0) dp[i * 2 + 1].f.pb((i - 1) * 2);
                if (a[i * 2 + 1].f.substr(0, i)  == a[(i - 1) * 2 + 1].f and dp[(i - 1) * 2 + 1].f.size() + dp[(i - 1) * 2 + 1].s.size() != 0) dp[i * 2 + 1].f.pb((i - 1) * 2 + 1);
            }
        }
    }

    /*
    for (int i = 0; i < 2 * n - 2; i++) {
        cout << a[i].f << endl;
        for (auto y : dp[i].f) cout << y << " ";
        cout << endl;
        for (auto y : dp[i].s) cout << y << " ";
        cout << endl;
    }
    */

    int start;
    if (dp[(n - 2) * 2].f.size() != 0) {
        start = (n - 2) * 2;
    }
    else {
        start = (n - 2) * 2 + 1;
    }

    while (start != -1) {
        ans[a[start].s] = true;
        start = dp[start].f[0];
    }

    for (auto x : ans) cout << (x ? 'P' : 'S');
    cout << endl;
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