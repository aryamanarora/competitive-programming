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

const int INF = numeric_limits<int>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi a(n); int maxi = 0, maxi2 = 0;
    for (auto &x : a) {
        cin >> x;
        if (x >= maxi) {
            maxi2 = maxi;
            maxi = x;
        }
        else maxi2 = max(x, maxi2);
    }
    sort(a.rbegin(), a.rend());

    int k = maxi + maxi2 + 1;
    vi dp(k, INF);
    dp[0] = 0;
    for (int i = 1; i < k; i++) {
        int greedy = 0, old_i = i;
        for (auto &x : a) {
            if (old_i >= x) {
                greedy += (old_i / x);
                old_i %= x;
            }
        }

        for (auto &x : a) {
            if (i >= x) dp[i] = min(dp[i - x] + 1, dp[i]);
        }

        // cout << i << ": " << greedy << " " << dp[i] << endl;

        if (dp[i] != greedy) {
            cout << "non-canonical" << endl;
            return 0;
        }
    }

    cout << "canonical" << endl;
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