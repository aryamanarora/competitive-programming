/*
ID: aryaman4
TASK: spin
LANG: C++14
*/

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

struct wheel {
    int speed, wedges;
    vii w;
    wheel(int s, int we) : speed(s), wedges(we) {};
    void push_back(int a, int b) {
        w.pb({a, b});
    }
    void next() {
        for (auto &wedge : w) {
            wedge.f = (wedge.f + speed) % 360;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("spin.in");
    ofstream cout("spin.out");

    vector<wheel> a;
    for (int i = 0, s, w; i < 5; i++) {
        cin >> s >> w;
        a.pb({s, w});
        for (int j = 0, l, r; j < w; j++) {
            cin >> l >> r;
            a[i].pb(l, r);
        }
    }

    si canpass;
    for (int t = 0; t < 360; t++) {
        vi ct(360);
        for (auto &x : a) {
            for (auto &w : x.w) {
                for (int i = 0; i <= w.s; i++) ct[(w.f + i) % 360]++;
            }
        }
        // cout << t << endl;
        for (int i = 0; i < 360; i++) {
            // cout << i << ": " << ct[i] << endl;
            if (ct[i] == 5) {
                cout << t << endl;
                return 0;
            }
        }
        for (auto &x : a) x.next();
    }
    cout << "none" << endl;
    return 0;
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