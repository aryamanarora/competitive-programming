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

    ifstream cin("248.in");
    ofstream cout("248.out");

    int n;
    cin >> n;
    vi a(n); for (auto &x : a) cin >> x;

    vector<vi> memo(n, vi(n, -1));

    int ans = 0;

    function<int(int, int)> dp = [&](int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];
        if (i == j) {
            memo[i][j] = a[i];
            ans = max(ans, a[i]);
        }
        else {
            for (int k = i; k < j; k++) {
                memo[i][j] = max(memo[i][j], (dp(i, k) == dp(k + 1, j) and dp(i, k) != 0 ? dp(i, k) + 1 : 0));
            }
            ans = max(ans, memo[i][j]);
        }
        return memo[i][j];
    };

    dp(0, n - 1);

    /*
    for (auto &x : memo) {
        for (auto &y : x) cout << y << " ";
        cout << endl;
    }
    */

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