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
    
    int n, m;
    cin >> n >> m;
    vector<pair<ii, int>> e(m);
    for (auto &x : e) {
        cin >> x.f.f >> x.f.s >> x.s;
        x.f.f--, x.f.s--;
    }
    vl d(n); vi p(n, -1);
    int x = -1;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto &v : e) {
            if (d[v.f.f] + v.s < d[v.f.s]) {
                d[v.f.s] = d[v.f.f] + v.s;
                p[v.f.s] = v.f.f;
                x = v.f.s;
            }
        }
        if (x == -1) break;
    }
    
    if (x == -1) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) x = p[x];
        vi cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x and cycle.size() > 1) break;
        }
        for (int i = cycle.size() - 1; i >= 0; i--) cout << cycle[i] + 1 << " ";
        cout << endl;
    }
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
