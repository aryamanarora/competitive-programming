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

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const ll INF = numeric_limits<ll>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll H, n;
    cin >> H >> n;
    vl d(n); for (auto &x : d) cin >> x;
    ll sum = 0;
    for (auto &x : d) sum += x;

    // sum * x + sum_i >= -H
    // sum * x >= -H - sum_i
    
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        H += d[i];
        if (sum < 0 and H > 0) {
            ll cur = H / -sum;
            while (H - (cur * -sum) > 0) cur++;
            if (cur < 0) continue;
            ans = min(ans, cur * n + i + 1);
        }
        else if (H <= 0) ans = min(ans, i + 1LL);
    }
    cout << (ans == INF ? -1 : ans) << endl;
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