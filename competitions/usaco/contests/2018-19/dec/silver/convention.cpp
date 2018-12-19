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

int n, m, c;
vi a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("convention.in");
    ofstream cout("convention.out");


    cin >> n >> m >> c;
    if (m >= n) {
        cout << 0 << endl;
        return 0;
    }

    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0, start = 0, ct = 0;
    for (int i = 0; i < n; i++) {
        ct++;
        if (ct == c) {
            ans = max(ans, a[i] - a[start]);
            start = i + 1;
            ct = 0;
        }
    }
    if (start != n) ans = max(ans, a[n - 1] - a[start]);
    cout << ans << endl;
}

/*

6: 1 1 3 4 10 14 0
5:   1 3 4 10 14 0
4:   1   4 10 14 1
3:   1   

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

1 2 3 4 5 6 7 8 9
1 2 3 4 5|6 7 8 9
*/

