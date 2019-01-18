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

void solve() {
    int n;
    cin >> n;

    vii events(n * 2);
    for (int i = 0; i < n; i++) {
        cin >> events[i * 2].f >> events[i * 2 + 1].f;
        events[i * 2].s = -i - 1; events[i * 2 + 1].s = i + 1;
    }
    sort(events.begin(), events.end());

    si cur;
    vi colour(n); bool two = false, one = false;
    for (auto &[t, id] : events) {
        if (id < 0) {
            if (cur.size() >= 1) colour[-id - 1] = colour[*cur.begin() - 1];
            else if (cur.size() == 0) {
                if (!two) {colour[-id - 1] = 2; two = true; }
                else { colour[-id - 1] = 1; one = true; }
            }
            cur.insert(-id);
        }
        else {
            cur.erase(id);
        }
    }

    if (!one or !two) {
        cout << -1 << endl;
        return;
    }
    for (auto &x : colour) cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
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