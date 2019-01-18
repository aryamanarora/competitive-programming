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

    ifstream cin("cowdance.in");
    ofstream cout("cowdance.out");

    int n, t;
    cin >> n >> t;
    vi a(n); for (auto &x : a) cin >> x;

    auto check = [&](int k) -> bool {
        priority_queue<int, vi, greater<int>> cows;
        for (int i = 0; i < n; i++) {
            if (cows.size() < k) cows.push(a[i]);
            else {
                cows.push(cows.top() + a[i]);
                cows.pop();
            }
        }

        int res;
        while (!cows.empty()) {
            res = cows.top();
            cows.pop();
        }
        // cerr << res;
        return (res <= t);
    };

    int lo = 1, hi = n; int ans = n;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        if (check(mid)) {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else lo = mid + 1;
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