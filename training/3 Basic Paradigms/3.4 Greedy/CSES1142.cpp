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
    vector<pair<ll, ll>> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i].f;
        k[i].s = i;
    }
    sort(k.rbegin(), k.rend());

    set<pair<ll, ll>> s;
    s.insert({-1, -1}); s.insert({n, n});
    ll ans = 0;

    for (auto &x : k) {
        pair<ll, ll> ins = {x.s, x.s};
        auto l = prev(s.lower_bound(ins));
        auto r = s.upper_bound(ins);

        if (l->s == ins.f - 1 and l->s != -1) {
            ins.f = l->f;
            s.erase(l);
        }
        if (r->f == ins.s + 1 and r->f != n) {
            ins.s = r->s;
            s.erase(r);
        }

        ans = max(ans, (ins.s - ins.f + 1) * x.f);
        s.insert(ins);
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