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
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("mixmilk.in");
    ofstream cout("mixmilk.out");

    ll c1, m1, c2, m2, c3, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    for (int i = 0; i < 100; i++) {
        if (i % 3 == 0) {
            ll give1 = m1;
            ll take2 = c2 - m2;
            m1 -= min(give1, take2);
            m2 += min(give1, take2);
        }
        else if (i % 3 == 1) {
            ll give2 = m2;
            ll take3 = c3 - m3;
            m2 -= min(give2, take3);
            m3 += min(give2, take3);
        }
        else if (i % 3 == 2) {
            ll give3 = m3;
            ll take1 = c1 - m1;
            m3 -= min(give3, take1);
            m1 += min(give3, take1);
        }
    }

    cout << m1 << endl << m2 << endl << m3 << endl;
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