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
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("convention2.in");
    ofstream cout("convention2.out");

    int n;
    cin >> n;
    set<array<int, 3>> events;
    int l, d;
    for (int i = 1; i <= n; i++) {
        cin >> l >> d;
        events.insert({l, i, d});
    }

    set<array<int, 3>> q;
    int eating = 0, end = 0, ans = 0;
    auto it = events.begin();
    for (auto x : events) {
        // cerr << x[1] << " " << x[0] << " ";
        if (x[1] > 0) q.insert({x[1], x[0], x[2]});
        else eating = 0;

        if (!eating and q.size() != 0) {
            array<int, 3> cur = *q.begin();
            q.erase(q.begin());
            if (end == 0) {
                eating = cur[0];
                end = cur[1] + cur[2];
                events.insert({end, -cur[0], cur[2]});
            }
            else {
                eating = cur[0];
                // cerr << end - cur[1];
                ans = max(end - cur[1], ans);
                end = max(end, cur[1]) + cur[2];
                events.insert({end, -cur[0], cur[2]});
            }
        }
        // cerr << endl;
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