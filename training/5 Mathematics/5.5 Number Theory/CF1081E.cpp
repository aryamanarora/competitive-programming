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

    vl squares;
    for (ll i = 1; i * i <= 1e13; i++) {
        squares.pb(i * i);
    }

    int n;
    cin >> n;
    vl a(n / 2); for (auto &x : a) cin >> x;
    ll sum = 0;
    vl ans;
    for (auto &x : a) {
        for (auto it = upper_bound(squares.begin(), squares.end(), sum); it != squares.end(); it++) {
            if (binary_search(squares.begin(), squares.end(), (*it) + x)) {
                ans.pb(*it - sum); ans.pb(x);
                sum = *it + x;
                break;
            }
            if (it + 1 == squares.end()) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    for (auto &x : ans) cout << x << " ";
    cout << endl;
}

/*
USE LONG LONG!!!!

:pray: :fishy15:
:pray: :summitosity:

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