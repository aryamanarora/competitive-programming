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

int ans = -1;

void dfs(int pos, int b, vector<vector<bool>> &dp, vii &boots, vi &a) {
    if (dp[pos][b] or a[pos] > boots[b].f) return;
    if (pos == dp.size() - 1) ans = max(ans, b);
    dp[pos][b] = true;
    for (int i = 1; i <= boots[b].s and pos + i < a.size(); i++) if (a[pos + i] <= boots[b].f) dfs(pos + i, b, dp, boots, a);
    for (; b >= 0; b--) if (a[pos] <= boots[b].f) dfs(pos, b, dp, boots, a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("snowboots.in");
    ofstream cout("snowboots.out");
    
    int n, b;
    cin >> n >> b;
    vi a(n); for (auto &x : a) cin >> x;
    vii boots;
    for (int i = 0, s, d; i < b; i++) {
        cin >> s >> d;
        boots.pb({s, d});
    }
    reverse(boots.begin(), boots.end());
    boots.pb({0, 1});
    
    vector<vector<bool>> dp(n, vector<bool>(b + 1));
    dfs(0, b, dp, boots, a);

    /*
    for (auto &x : dp) {
        for (const bool &y : x) cerr << y << " ";
        cerr << endl;
    }
    */

   cout << b - (ans + 1) << endl;
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