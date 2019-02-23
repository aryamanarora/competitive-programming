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

    ifstream cin("art2.in");
    ofstream cout("art2.out");

    int n;
    cin >> n;
    vi a(n); for (auto &x : a) cin >> x;

    vii depth(n, {-1, -1});
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        if (depth[a[i] - 1].f == -1) depth[a[i] - 1].f = i;
        depth[a[i] - 1].s = max(depth[a[i] - 1].s, i);
    }

    vii events;
    for (int i = 0; i < n; i++) {
        if (depth[i].f == -1 or depth[i].s == -1) continue;
        events.pb({depth[i].f, -(i + 1)});
        events.pb({depth[i].s, (i + 1)});
    }
    sort(events.begin(), events.end());

    int ans = 0;
    vi active;
    for (auto &x : events) {
        if (x.s < 0) active.push_back(-x.s);
        else {
            if (active.back() != x.s) {
                cout << -1 << endl;
                return 0;
            }
            else active.pop_back();
        }
        ans = max(ans, static_cast<int>(active.size()));
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