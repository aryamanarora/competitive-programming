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

    ifstream cin("helpcross.in");
    ofstream cout("helpcross.out");

    int c, n;
    cin >> c >> n;
    vii events;
    for (int i = 0, j; i < c; i++) {
        cin >> j;
        events.pb({j, 0});
    }
    map<int, int> end;
    for (int i = 0, j, k; i < n; i++) {
        cin >> j >> k;
        events.pb({j, -(i + 1)});
        events.pb({k, i + 1});
        end[i + 1] = k;
    }
    sort(events.begin(), events.end());

    int ans = 0;
    sii cows;
    for (auto &x : events) {
        if (x.s == 0) {
            if (cows.size() != 0) {
                cows.erase(cows.begin());
                ans++;
            }
        }
        else {
            if (x.s < 0) cows.insert({end[-x.s], -x.s});
            else cows.erase({end[x.s], x.s});
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