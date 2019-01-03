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

int maxi(int d1, int h1, int d2, int h2) {
    int lo = min(h1, h2), hi = max(h1, h2), dist = d2 - d1;
    if (hi - lo > dist) return -1;
    return (hi - lo) / 2 + (dist % 2 ? (hi - lo) % 2 : 0) + lo + (dist / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vii a(m);
    for (auto &x : a) cin >> x.f >> x.s;
    int ans = 0;
    for (int i = 0; i < m - 1; i++) {
        int d = maxi(a[i].f, a[i].s, a[i + 1].f, a[i + 1].s);
        if (d == -1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        ans = max(ans, d);
    }
    ans = max(ans, a[0].f - 1 + a[0].s);
    ans = max(ans, n - a[m - 1].f + a[m - 1].s);
    cout << ans << endl;
}

/*
USE LONG LONG!!!!

2 0
7 0

2 3 4 5 6 7
0 1 2 2 1 0 2
0 1 2 3 2 1 3
0 1 2 3 3 2 3
0 1 2 3 4 3 4
0 1 2 3 4 4 4
0 1 2 3 4 5 5

0 1 2 1 0 2
0 1 2 2 1 2
0 1 2 3 2 3
0 1 2 3 3 3
0 1 2 3 4 4

0 1 1 0 1
0 1 2 1 2
0 1 2 2 2
0 1 2 3 3

0 1 0 1
0 1 1 1
0 1 2 2

0 0 0
0 1 1

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