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

    ifstream cin("cownomics.in");
    ofstream cout("cownomics.out");

    int n, m;
    cin >> n >> m;
    set<string> as, bs;
    vector<string> a(n), b(n), ac(n), bc(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    auto check = [&](int len) {
        for (int i = 0; i < n; i++) {
            ac[i] = a[i].substr(0, len);
            bc[i] = b[i].substr(0, len);
        }
        for (int i = len; i < m; i++) {
            as.clear();
            bs.clear();
            for (int j = 0; j < n; j++) {
                as.insert(ac[j]);
                bs.insert(bc[j]);
                ac[j].erase(ac[j].begin());
                ac[j].pb(a[j][i]);
                bc[j].erase(bc[j].begin());
                bc[j].pb(b[j][i]);
            }
            bool match = false;
            for (auto &x : as) {
                if (bs.count(x)) {
                    match = true;
                    break;
                }
            }
            if (!match) return true;
        }
        for (int j = 0; j < n; j++) {
            as.insert(ac[j]);
            bs.insert(bc[j]);
        }
        bool match = false;
        for (auto &x : as) {
            if (bs.count(x)) {
                match = true;
                break;
            }
        }
        if (!match) return true;
        return false;
    };

    int lo = 1, hi = m;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid - 1;
        else lo = mid + 1;
    }

    cout << lo << endl;
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