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

    ifstream cin("split.in");
    ofstream cout("split.out");

    int n;
    cin >> n;
    vii a(n); for (auto &x : a) cin >> x.f >> x.s;
    sort(a.begin(), a.end());

    vi premax(n), premin(n), sufmax(n), sufmin(n);

    // left to right sweep

    for (int i = 0; i < n; i++) {
        premax[i] = premin[i] = a[i].s;
        if (i > 0) premax[i] = max(premax[i], premax[i - 1]), premin[i] = min(premin[i], premin[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        sufmax[i] = sufmin[i] = a[i].s;
        if (i < n - 1) sufmax[i] = max(sufmax[i], sufmax[i + 1]), sufmin[i] = min(sufmin[i], sufmin[i + 1]);
    }

    ll one = static_cast<ll>(premax[n - 1] - premin[n - 1]) * static_cast<ll>(a[n - 1].f - a[0].f);
    ll ans = 0;

    for (int i = 0; i < n - 1; i++) {
        ans = max(
            ans, 
            one - static_cast<ll>(premax[i] - premin[i]) * static_cast<ll>(a[i].f - a[0].f) -
            static_cast<ll>(sufmax[i + 1] - sufmin[i + 1]) * static_cast<ll>(a[n - 1].f - a[i + 1].f)
        );
    }

    // down to up sweep
    sort(a.begin(), a.end(), [](const ii &a, const ii &b) {
        return a.s < b.s;
    });

    for (int i = 0; i < n; i++) {
        premax[i] = premin[i] = a[i].f;
        if (i > 0) premax[i] = max(premax[i], premax[i - 1]), premin[i] = min(premin[i], premin[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        sufmax[i] = sufmin[i] = a[i].f;
        if (i < n - 1) sufmax[i] = max(sufmax[i], sufmax[i + 1]), sufmin[i] = min(sufmin[i], sufmin[i + 1]);
    }

    for (int i = 0; i < n - 1; i++) {
        ans = max(
            ans, 
            one - static_cast<ll>(premax[i] - premin[i]) * static_cast<ll>(a[i].s - a[0].s) -
            static_cast<ll>(sufmax[i + 1] - sufmin[i + 1]) * static_cast<ll>(a[n - 1].s - a[i + 1].s)
        );
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