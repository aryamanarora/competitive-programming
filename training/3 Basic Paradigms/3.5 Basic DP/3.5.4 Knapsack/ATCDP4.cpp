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

ll dp(int i, int w, vector<vl> &memo) {
    if (memo[i][w] != -1) return memo[i][w];
    if (w == 0) memo[i][w] = 0;
    else if (i == n) memo[i][w] = 0;
    else if (a[i].f > w) memo[i][w] = dp(i + 1, w, memo);
    else memo[i][w] = max(dp(i + 1, w, memo), a[i].s + dp(i + 1, w - a[i].f, memo));
    return memo[i][w];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w;
    cin >> n >> w;
    a.resize(n);
    for (auto &x : a) cin >> x.f >> x.s;
    vector<vl> memo(n + 1, vl(w + 1, -1));

    cout << dp(0, w, memo) << endl;
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