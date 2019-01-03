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
    
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    vector<vi> ans(n, vi(m, numeric_limits<int>::max()));
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            if (a[j][k] == '.') {
                ans[j][k] = 0;
                if (k < m - 1) if (a[j][k + 1] == 'T') ans[j][k + 1] = 1;
                if (k > 0) if (a[j][k - 1] == 'T') ans[j][k - 1] = 1;
                if (j < n - 1) if (a[j + 1][k] == 'T') ans[j + 1][k] = 1;
                if (j > 0) if (a[j - 1][k] == 'T') ans[j - 1][k] = 1;
            }
            else if (a[j][k] == 'T') {
                if (k == 0 or k == m - 1 or j == 0 or j == n - 1) ans[j][k] = 1;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            if (ans[j][k] == 1) {
                for (int l = 0; l < n; l++) {
                    for (int o = 0; o < m; o++) ans[l][o] = min(ans[l][o], 1 + abs(l - j) + abs(o - k));
                }
            }
        }
    }

    int maxi = 0;
    for (auto &x : ans) {
        for (auto &y : x) maxi = max(maxi, y);
    }

    if (maxi < 10) {
        for (auto &x : ans) {
            for (auto &y : x) {
                if (y == 0) cout << "..";
                else cout << "." << y;
            }
            cout << endl;
        }
    }
    else {
        for (auto &x : ans) {
            for (auto &y : x) {
                if (y == 0) cout << "...";
                else cout << setw(3) << setfill('.') << right << y;
            }
            cout << endl;
        }
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