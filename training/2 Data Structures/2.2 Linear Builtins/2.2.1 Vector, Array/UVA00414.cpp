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

bool solve() {
    int n;
    cin >> n;
    if (n == 0) return false;
    vi a(n, 0);
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        // cout << s << endl;
        for (auto x : s) if (x == 'X') a[i]++;
    }

    int maxi = *max_element(a.begin(), a.end());

    int ans = 0;
    for (auto x : a) ans += (maxi - x);
    cout << ans << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (solve()) {
        
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