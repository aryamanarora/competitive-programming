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

    int n;
    cin >> n;
    vii a(n); for (auto &x : a) cin >> x.f >> x.s;
    for (int i = 1; i < n; i++) {
        if ((a[i].s < 0 and a[i - 1].s > 0) or (a[i].s > 0 and a[i - 1].s < 0)) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (auto &x : a) x.s = abs(x.s);

    auto check = [&](ld r) {
        ld lo = -numeric_limits<ld>::infinity(), hi = numeric_limits<ld>::infinity();
        for (auto &x : a) {
            ld y = abs(r - static_cast<ld>(x.s));
            ld dist = sqrt(r * r - y * y);
            ld lox = static_cast<ld>(x.f) - dist, hix = static_cast<ld>(x.f) + dist;
            if (lo <= hix and lox <= hi) lo = max(lo, lox), hi = min(hi, hix);
            else return false;
        }
        return true;
    };

    int ct = 0;
    ld lo = 0.0, hi = 1e17;
    while (ct < 1000) {
        ld mid = (lo + hi) / ld(2.0);
        if (check(mid)) hi = mid;
        else lo = mid;
        ct++;
    }

    cout << fixed << setprecision(10) << lo << endl;
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