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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("feast.in");
    ofstream cout("feast.out");

    int t, a, b;
    cin >> t >> a >> b;
    vector<bool> can_make(t + 1), can_half(t + 1);
    can_make[0] = can_half[0] = true;
    for (int i = 1; i <= t; i++) {
        if (i >= a) if (can_half[i - a]) can_half[i] = true;
        if (i >= b) if (can_half[i - b]) can_half[i] = true;
        if (can_half[i]) can_make[i / 2] = true;
    }
    int ans = 0;
    for (int i = 1; i <= t; i++) {
        if (i >= a) if (can_make[i - a]) can_make[i] = true;
        if (i >= b) if (can_make[i - b]) can_make[i] = true;
        if (can_make[i]) ans = max(ans, i);
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