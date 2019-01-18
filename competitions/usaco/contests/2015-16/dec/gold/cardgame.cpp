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
typedef vector<bool> vb;

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;

typedef vector<vi> vvi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int END = 1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("cardgame.in");
    ofstream cout("cardgame.out");

    int n;
    cin >> n;
    si bessie;
    for (int i = 1; i <= 2 * n; i++) bessie.insert(i);
    vii a;
    for (int i = 1, x; i <= n; i++) {
        if (i > n / 2) {
            cin >> x;
            bessie.erase(x);
            a.pb({x, END}); a.pb({0, x});
        }
        else {
            cin >> x;
            bessie.erase(x);
            a.pb({n * 2, END}); a.pb({x, n * 2});
        }
    }
    for (auto &x : bessie) a.pb({x, 0});

    sort(a.begin(), a.end());
    // for (auto &x : a) cerr << x.f << " " << x.s << endl;

    multiset<int> intervals;
    int ans = 0;
    for (auto &x : a) {
        /*
        cerr << x.f << " " << x.s << endl;
        cerr << intervals.size() << ": ";
        for (auto &x : intervals) cerr << x << " ";
        cerr << endl;
        */
        if (x.s == 0) {
            if (intervals.size() != 0) {
                intervals.erase(intervals.begin());
                ans++;
            }
        }
        else if (x.s == END) {
            auto it = intervals.find(x.f);
            if (it != intervals.end()) intervals.erase(it);
        }
        else intervals.insert(x.s);
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

1-------
       8
---4
--3
*/