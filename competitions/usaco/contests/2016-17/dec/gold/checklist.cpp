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

int dist(ii a, ii b) {
    return pow(a.f - b.f, 2) + pow(a.s - b.s, 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("checklist.in");
    ofstream cout("checklist.out");

    int h, g;
    cin >> h >> g;
    vector<pair<ll, ll>> hol(h); for (auto &x : hol) cin >> x.f >> x.s;
    vector<pair<ll, ll>> gur(g); for (auto &x : gur) cin >> x.f >> x.s;

    vector<vector<pair<ll, bool>>> dp(g + 1, vector<pair<ll, bool>>(h - 1, {1000000000000000, false}));
    for (int i = 0; i <= g; i++) {
        for (int j = 0; j < h - 1; j++) {
            ll cont = dist(hol[j], hol[j + 1]);
            if (i == 0) {
                if (j == 0) dp[i][j] = {cont, false};
                else dp[i][j] = {dp[i][j - 1].f + cont, false};
            }

            ll d = dist(hol[j], gur[i - 1]) + dist(gur[i - 1], hol[j + 1]);
            if (j > 0) {
                // last position better
                if (dp[i][j - 1].f + cont < dp[i][j].f) dp[i][j] = {dp[i][j - 1].f + cont, false};
                // new position better: HGHGH
                if (dp[i - 1][j - 1].f + d < dp[i][j].f) dp[i][j] = {dp[i - 1][j - 1].f + d, false};
            }
            else if (i == 1) {
                dp[i][j] = {d, true};
            }

            // stacking with previous: HGG...GH
            if (dp[i - 1][j].s) {
                ll d_cont = dist(gur[i - 1], gur[i]) + dist(gur[i], hol[j + 1]);
                ll d_stack = dp[i - 1][j].f - dist(gur[i - 1], hol[j + 1]) + d_cont;
                if (d_stack < dp[i][j].f) dp[i][j] = {d_stack, true};
            }
        }
    }

    for (auto &x : dp) {
        for (auto &y : x) cerr << y.f << " (" << y.s << ") ";
        cerr << endl;
    }

    cout << dp[g][h - 2].f << endl;
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