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

    ifstream cin("mountains.in");
    ofstream cout("mountains.out");

    int n;
    cin >> n;
    vii events;
    mii start, end;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        if (!start.count(x + y)) start[x + y] = x - y;
        else start[x + y] = min(start[x + y], x - y);
        if (!end.count(x - y)) end[x - y] = x + y;
        else end[x - y] = max(end[x - y], x + y);
    }

    int ct = 1;
    for (auto &x : start) {
        if (end[x.s] == x.f) {
            events.pb({x.f, -ct});
            events.pb({x.s, ct});
            ct++;
        }
    }

    sort(events.begin(), events.end());

    int ans = 0;
    sii cur;
    for (int i = 0; i < events.size(); i++) {
        // cout << events[i].f << " " << events[i].s << endl;
        if (events[i].s > 0) {
            cur.insert({events[i].f, events[i].s});
        }
        else if (-events[i].s == cur.begin()->s) {
            ans++;
            cur.erase(cur.begin());
        }
        else {
            cur.erase({start[events[i].f], -events[i].s});
        }
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