// ITS WRONG USE DP

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

ld ans = 0.0, ansd = 0.0;
map<pair<ld, ld>, ld> memo;
ld prob(ld w, ld b) {
    cout << w << " " << b << endl;
    if (w == 0.0 and b == 0.0) return 0.0;
    else if (w == 0.0) return 0.0;
    else if (b == 0.0) return 1.0;
    if (memo.count({w, b})) return memo[{w, b}];

    ld ans = (w / (b + w));
    b--; // black is drawn
    ld dragon = (b / (w + b)); // dragon draws black

    // dragon black * black escape * probability now
    ans += dragon * ((b - 1) / (w + b - 1)) * prob(w, b - 2);
    ans += dragon * ((w - 1) / (w + b - 1)) * prob(w - 1, b - 1);
    memo[{w, b}] = ans;
    return memo[{w, b}];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, b;
    cin >> w >> b;
    cout << prob(w, b) << endl;
}

/*
USE LONG LONG!!!!

W:
B:BB(B)
  BB(W)


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