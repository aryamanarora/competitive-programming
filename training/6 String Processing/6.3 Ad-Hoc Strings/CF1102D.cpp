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

    int n; string s;
    cin >> n >> s;
    int z = 0, o = 0, t = 0;
    for (auto &x : s) {
        if (x == '2') t++;
        else if (x == '1') o++;
        else z++;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '2' and t > n / 3) {
            if (z < n / 3) { s[i] = '0'; z++; }
            else { s[i] = '1'; o++; }
            t--;
        }
        else if (s[i] == '1' and o > n / 3) {
            if (z < n / 3) { s[i] = '0'; z++; o--; }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0' and z > n / 3) {
            if (t < n / 3) { s[i] = '2'; t++; }
            else { s[i] = '1'; o++; }
            z--;
        }
        else if (s[i] == '1' and o > n / 3) {
            if (t < n / 3) { s[i] = '2'; t++; o--; }
        }
    }

    cout << s << endl;
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