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

    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vi> kk(n, vi(n, 0));
    kk[0][0] = k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (kk[i][j] > 0) {
                if (a[i][j] == 'a') {
                    if (i != n - 1) kk[i + 1][j] = max(kk[i + 1][j], kk[i][j]);
                    if (j != n - 1) kk[i][j + 1] = max(kk[i][j + 1], kk[i][j]);
                }
                else {
                    a[i][j] = 'a';
                    if (i != n - 1) kk[i + 1][j] = max(kk[i + 1][j], kk[i][j] - 1);
                    if (j != n - 1) kk[i][j + 1] = max(kk[i][j + 1], kk[i][j] - 1);
                }
            }
        }
    }

    vector<vector<bool>> search(n, vector<bool>(n, false));
    search[0][0] = true;
    string ans(1, a[0][0]);
    for (int i = 0; i < n * 2 - 2; i++) {
        char minchar = 'z';
        for (int j = min(n - 1, i), k = max(i - (n - 1), 0); j >= 0 and k < n; j--, k++) {
            if (search.at(j).at(k)) {
                if (j != n - 1) minchar = min(minchar, a.at(j + 1).at(k));
                if (k != n - 1) minchar = min(minchar, a.at(j).at(k + 1));
            }
        }

        ans.pb(minchar);

        for (int j = min(n - 1, i), k = max(i - (n - 1), 0); j >= 0 and k < n; j--, k++) {
            if (search.at(j).at(k)) {
                if (j != n - 1) if (a.at(j + 1).at(k) == minchar) search.at(j + 1).at(k) = true;
                if (k != n - 1) if (a.at(j).at(k + 1) == minchar) search.at(j).at(k + 1) = true;
            }
        }
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