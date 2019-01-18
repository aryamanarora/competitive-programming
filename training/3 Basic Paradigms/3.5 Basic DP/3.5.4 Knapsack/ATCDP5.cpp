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

int n; vector<pair<int, ll>> a;
map<pair<int, ll>, ll> memo;

ll dp(int i, int w) {
    if (memo.count({i, w})) return memo[{i, w}];
    if (w == 0) memo[{i, w}] = 0;
    else if (i == n) memo[{i, w}] = 0;
    else if (a[i].f > w) memo[{i, w}] = dp(i + 1, w);
    else memo[{i, w}] = max(dp(i + 1, w), a[i].s + dp(i + 1, w - a[i].f));
    return memo[{i, w}];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w;
    cin >> n >> w;
    a.resize(n);
    for (auto &x : a) cin >> x.f >> x.s;

    cout << dp(0, w) << endl;
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