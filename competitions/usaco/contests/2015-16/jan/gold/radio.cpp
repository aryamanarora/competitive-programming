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

    ifstream cin("radio.in");
    ofstream cout("radio.out");

    function<ll(ii, ii)> dist = [&](ii a, ii b) {
        return (static_cast<ll>(a.f - b.f) * static_cast<ll>(a.f - b.f) + static_cast<ll>(a.s - b.s) * static_cast<ll>(a.s - b.s));
    };

    int n, m, x1, y1, x2, y2; string a, b;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> a >> b;
    vii pos1(n + 1), pos2(m + 1);
    pos1[0] = {x1, y1}, pos2[0] = {x2, y2};
    for (int i = 0; i < n; i++) {
        if (a[i] == 'N') pos1[i + 1] = {pos1[i].f, pos1[i].s + 1};
        else if (a[i] == 'S') pos1[i + 1] = {pos1[i].f, pos1[i].s - 1};
        else if (a[i] == 'E') pos1[i + 1] = {pos1[i].f + 1, pos1[i].s};
        else if (a[i] == 'W') pos1[i + 1] = {pos1[i].f - 1, pos1[i].s};
    }
    for (int i = 0; i < m; i++) {
        if (b[i] == 'N') pos2[i + 1] = {pos2[i].f, pos2[i].s + 1};
        else if (b[i] == 'S') pos2[i + 1] = {pos2[i].f, pos2[i].s - 1};
        else if (b[i] == 'E') pos2[i + 1] = {pos2[i].f + 1, pos2[i].s};
        else if (b[i] == 'W') pos2[i + 1] = {pos2[i].f - 1, pos2[i].s};
    }

    /*
    cerr << endl;
    for (auto &x : pos1) cerr << x.f << " " << x.s << endl;
    cerr << endl;
    for (auto &x : pos2) cerr << x.f << " " << x.s << endl;
    cerr << endl;
    */

    vector<vl> dp(n + 1, vl(m + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i != 0 or j != 0) dp[i][j] =  dist(pos1[i], pos2[j]);
            if (i > 0 and j > 0) dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            else if (i > 0) dp[i][j] += dp[i - 1][j];
            else if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[n][m] << endl;

    /*
    for (auto &x : dp) {
        for (auto &y : x) cerr << y << " ";
        cerr << endl;
    }
    */
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