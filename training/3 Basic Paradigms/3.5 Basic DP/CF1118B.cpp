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
    vl a(n); for (auto &x : a) cin >> x;

    vl prefixsum(n), suffixsum(n);
    for (int i = 0; i < n; i++) {
        prefixsum[i] = a[i];
        if (i - 2 >= 0) prefixsum[i] += prefixsum[i - 2];
    }
    for (int i = n - 1; i >= 0; i--) {
        suffixsum[i] = a[i];
        if (i + 2 < n) suffixsum[i] += suffixsum[i + 2];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll a = 0;
        if (i - 1 >= 0) a += prefixsum[i - 1];
        if (i + 2 < n) a += suffixsum[i + 2];

        ll b = 0;
        if (i - 2 >= 0) b += prefixsum[i - 2];
        if (i + 1 < n) b += suffixsum[i + 1];

        if (a == b) ans++;
    }

    cout << ans << endl;
}

/*
USE LONG LONG!!!!

:pray: :fishy15:
:pray: :summitosity:
:pray: :prodakcin:

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