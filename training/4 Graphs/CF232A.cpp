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

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vi all;
    int ans = 6;
    for (int i = 4; i < 100; i++) {
        all.push_back(ans / 6);
        ans = (ans * i) / (i - 3);
    }

    int p = 0;
    vector<vi> g(100, vi(100));
    for (int i = all.size() - 1; i >= 0; i--) {
        if (all[i] <= n) {
            for (int j = 0; j < i + 3; j++) {
                for (int k = 0; k < i + 3; k++) {
                    if (j != k) g[j][k] = 1;
                }
            }
            n -= all[i];
            p = i + 3;
            break;
        }
    }

    for (int i = all.size() - 2; i >= 0; i--) all[i + 1] -= all[i];
    while (n) {
        for (int i = all.size() - 1; i >= 0; i--) {
            if (all[i] <= n) {
                for (int j = p; j > p - i - 3; j--) {
                    if (j != p) g[j][p] = g[p][j] = 1;
                }
                n -= all[i];
                p++;
                break;
            }
        }
    }

    cout << p << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) cout << g[i][j];
        cout << endl;
    }
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