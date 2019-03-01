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

    ifstream cin("dishes.in");
    ofstream cout("dishes.out");

    int n;
    cin >> n;

    vi a(n); for (auto &x : a) cin >> x;

    auto check = [&](int val) {
        map<int, vi> s; vi placed;
        s[a[0]].pb(a[0]);
        int i;
        for (i = 1; i < val; i++) {
            if (a[i] > a[i - 1]) s[a[i]].pb(a[i]);
            else break;
        }
        if (i == val) return true;
        for (; i < val; i++) {
            auto ins = s.lower_bound(a[i]);
            if (ins == s.end()) {
                s[a[i]].pb(a[i]);
                continue;
            }
            while (ins->s.back() < a[i]) {
                placed.pb(s.begin()->s.back());
                s.begin()->s.pop_back();
                if (s.begin()->s.empty()) s.erase(s.begin());
            }
            ins->s.pb(a[i]);
        }

        while (!s.empty()) {
            while (!s.begin()->s.empty()) {
                placed.pb(s.begin()->s.back());
                s.begin()->s.pop_back();
            }
            s.erase(s.begin());
        }

        return is_sorted(placed.begin(), placed.end());
    };

    int lo = 2, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << hi << endl;
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