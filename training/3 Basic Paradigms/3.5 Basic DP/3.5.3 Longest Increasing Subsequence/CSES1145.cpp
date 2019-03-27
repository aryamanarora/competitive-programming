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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi a(n); for (auto &x : a) cin >> x;

    int ans = 0;
    sii s; s.insert({0, 0});
    for (auto &x : a) {
        auto it = s.lower_bound({x, 0});
        int cur = prev(it)->s + 1;
        while (it != s.end()) {
            if (it->f == x) {
                cur = max(cur, it->s);
                it = s.erase(it);
            }
            else break;
        }
        while (it != s.end()) {
            if (it->s <= cur) {
                it = s.erase(it);
            }
            else break;
        }
        ans = max(ans, cur);
        s.insert({x, cur});
        // cout << endl;
        // for (auto &x : s) cout << x.f << " " << x.s << endl;
    }

    cout << ans << endl;
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