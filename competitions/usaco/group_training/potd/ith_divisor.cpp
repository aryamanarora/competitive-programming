/*
12/3 (thanks to @i'm 2185 on CF):
(Silver)
Given two arrays of length n, A and B, find the A[i]th divisor of B[i] for each i.
1<=n, B[i]<=2*10^6
*/

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

const int MAX = 2000001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vi> divs(MAX);
    for (int i = 1; i * i <= MAX; i++) {
        // cout << i << endl;
        for (int j = i * i; j <= MAX; j += i) {
            divs[j].pb(i);
        }
    }
    /*
    for (int i = 0; i < 100; i++) {
        for (auto x : divs[i]) cout << x << " ";
        cout << endl;
    }
    */

    int n;
    cin >> n;
    vi a(n); int b;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b;
        if (a[i] > divs[b].size()) {
            if (divs[b].back() * divs[b].back() == b) {
                cout << b / (divs[b][divs[b].size() - (a[i] - divs[b].size()) - 1]) << endl;
            }
            else {
                cout << b / (divs[b][divs[b].size() - (a[i] - divs[b].size())]) << endl;
            }
        }
        else {
            cout << divs[b][a[i] - 1] << endl;
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