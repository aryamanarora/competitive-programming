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

    int n;
    cin >> n;
    if (n <= 2) {
        cout << n << endl;
        return 0;
    }
    vi a(n); for (auto &x : a) cin >> x;

    vi pref(n), suf(n);
    for (int i = 0; i < n; i++) {
        pref[i] = 1;
        if (i > 0) if (a[i - 1] < a[i]) pref[i] = max(pref[i], pref[i - 1] + 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = 1;
        if (i < n - 1) if (a[i + 1] > a[i]) suf[i] = max(suf[i], suf[i + 1] + 1);
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (i < n - 1) ans = max(ans, suf[i + 1] + 1);
        if (i > 0) ans = max(ans, pref[i - 1] + 1);
        if (i < n - 1 and i > 0) {
            if (a[i + 1] > a[i - 1] + 1) ans = max(ans, pref[i - 1] + 1 + suf[i + 1]);
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