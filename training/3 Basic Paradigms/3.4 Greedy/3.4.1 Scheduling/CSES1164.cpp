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
    vii e;
    int ct = 0;
    for (int i = 1, l, r; i <= n; i++) {
        cin >> l >> r;
        e.pb({l, -i});
        e.pb({r, i});
    }
    sort(e.begin(), e.end());

    si unused, used;
    vi ans(n + 1);
    for (auto &x : e) {
        if (x.s < 0) {
            if (unused.empty()) {
                ans[-x.s] = used.size() + 1;
                used.insert(used.size() + 1);
            }
            else {
                ans[-x.s] = *unused.begin();
                used.insert(*unused.begin());
                unused.erase(unused.begin());
            }
        }
        else {
            unused.insert(ans[x.s]);
            used.erase(ans[x.s]);
        }
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

/*
USE LONG LONG!!!!

205
100->5

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