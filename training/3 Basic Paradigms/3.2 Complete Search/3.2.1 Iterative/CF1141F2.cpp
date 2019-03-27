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
    for (int i = 1; i < n; i++) a[i] += a[i - 1];

    map<int, sii> sums;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sums[a[j] - (i == 0 ? 0 : a[i - 1])].insert(mp(j, i));
        }
    }

    vii anss;
    for (auto &x : sums) {
        vii cur;
        for (auto &y : x.s) {
            if (cur.empty()) cur.push_back(y);
            else if (cur.back().f < y.s) cur.push_back(y);
        }
        if (cur.size() > anss.size()) anss = cur;
    }

    cout << anss.size() << '\n';
    for (auto &x : anss) cout << x.s + 1 << " " << x.f + 1 << '\n';
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