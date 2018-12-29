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

    ifstream cin("gradina3.in");
    ofstream cout("gradina3.out");

    int n, p, k;
    cin >> n >> p >> k;
    vector<vi> a(n, vi(n, 0));

    int x, y;
    for (int i = 0; i < p; i++) {
        cin >> x >> y;
        a[x - 1][y - 1]++;
    }

    // range sum
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) a[i][j] += a[i - 1][j];
            if (j > 0) a[i][j] += a[i][j - 1];
            if (i > 0 and j > 0) a[i][j] -= a[i - 1][j - 1];
        }
    }

    // now check all ranges
    int ans = 0; int anss = 0;
    for (int i = k - 1; i < n; i++) {
        for (int j = k - 1; j < n; j++) {
            int cur = a[i][j];
            if (i >= k) cur -= a[i - k][j];
            if (j >= k) cur -= a[i][j - k];
            if (i >= k and j >= k) cur += a[i - k][j - k];
            if (cur > ans) {
                ans = cur;
                anss = 1;
            }
            else if (cur == ans) {
                anss++;
            }
        }
    }

    // ans
    cout << ans << endl << anss << endl;
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