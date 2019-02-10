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

    string s; int k;
    cin >> s >> k;

    map<int, int> ct; int cur = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '*' or s[i] == '?') continue;
        if (s[i + 1] == '*' or s[i + 1] == '?') ct[i] = 0;
        else {
            ct[i] = 1;
            cur++;
        }
    }

    if (cur > k) {
        cout << "Impossible" << endl;
        return 0;
    }

    while (cur < k) {
        bool found = false;
        for (auto &x : ct) {
            if (s[x.f + 1] == '?' and x.s == 0) {
                x.s++;
                cur++;
                found = true;
                break;
            }
            if (s[x.f + 1] == '*') {
                x.s++;
                cur++;
                found = true;
                break;
            }
        }
        if (found == false and cur < k) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    for (auto &x : ct) {
        for (int i = 0; i < x.s; i++) cout << s[x.f];
    }
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