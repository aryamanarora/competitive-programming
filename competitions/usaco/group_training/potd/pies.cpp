/*
1/7 (thanks to @dolphingarlic)
There are n<=3000 pies in a row, with pie i containing Ai grams of sugar.
You also have m<=100 additional pies, with pie j containing Bj grams of sugar.
You can insert any of the m pies from the second group anywhere in the line,
but the relative order of the first group of pies must stay the same. You eat
pies from left to right and you can't eat 2 consecutive pies. Maximize the amount
of sugar you can obtain.
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

void dfs(int pos, vi &a, vi &b, vector<bool> &used) {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    sort(b.begin(), b.end());
    vi l(m, -1);
    int pos = 1; bool flip = false;
    for (int i = 0; i < m; i++) {
        if (flip) {
            l[pos] = b[i];
            pos -= 2;
        }
        if (pos < m) { 
            l[pos] = b[i];
            pos += 2;
        }
        else {
            for (pos = m - 1; pos >= 0; pos--) if (l[pos] == -1) break;
            flip = true;
        }
    }

    for (auto &x : l) cout << x << " ";
    cout << endl;
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