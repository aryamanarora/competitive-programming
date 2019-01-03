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

    ifstream cin("convention.in");
    ofstream cout("convention.out");

    int n, m, c;
    cin >> n >> m >> c;
    vi a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    int lo = 0, hi = a[n - 1] - a[0], mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int buses = 1, last = a[0], cows = 0;
        // cerr << mid << ": ";
        for (auto &x : a) {
            if (x - last > mid or cows == c) {
                buses++;
                last = x;
                cows = 1;
                // cerr << " | ";
            }
            else cows++;
            // cerr << x << " ";
        }
        // cerr << ": " << buses << endl;
        if (buses > m) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << lo << endl;
}

/*
1 1 3 4 10 14
13: [1 1 3 4 10 14]
12: [1 1 3 4 10][14]
...
8: [1 1 3 4][10 14]
9: 

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

