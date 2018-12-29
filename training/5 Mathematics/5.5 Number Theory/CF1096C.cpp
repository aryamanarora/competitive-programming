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

    vl ans(181, -1);
    for (int n = 3; n <= 360; n++) {
        int ang = (n - 2) * 180;
        ld angg = (static_cast<ld>(ang) / static_cast<ld>(n)) / (static_cast<ld>(n) - 2);
        for (int i = 1; i <= n - 2; i++) {
            ld intpart;
            if (modf(angg * static_cast<ld>(i), &intpart) == 0.0) {
                if (ans[static_cast<int>(intpart)] == -1) ans[static_cast<int>(intpart)] = n;
            }
        }
    }

    cout << 179 << endl;
    for (int i = 1; i < 180; i++) cout << i << endl;

    int t;
    cin >> t;
    while (t--) {
        int ang;
        cin >> ang;
        cout << ans[ang] << endl;
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