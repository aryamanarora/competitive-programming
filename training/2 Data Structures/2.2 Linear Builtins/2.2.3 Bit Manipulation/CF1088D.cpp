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

void query(int a, int b, int &c) {
    cout << "? " << fixed << setprecision(0) << a << " " << b << endl;
    cin >> c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a = 0, b = 0;
    int greater;
    query(0, 0, greater);
    for (int i = 29; i >= 0; i--) {
        int resa, resb;
        query(a + pow(2, i), b, resa);
        query(a, b + pow(2, i), resb);

        if (resa == resb) {
            if (greater == -1) b += pow(2, i);
            else a += pow(2, i);
            if (resa == -1) greater = -1;
            else greater = 1;
        }
        else if (resa == -1 and resb == 1) {
            a += pow(2, i);
            b += pow(2, i);
        }
        // cout << a << " " << b << endl;
    }
    cout << "! " << fixed << setprecision(0) << a << " " << b << endl;
}

/*
    1  0 -1
 1 01    00
 0    ?? 
-1 11    10

110           111
101           101

010 -1 110 +1 011 -1 111 +1
101    001    101    001

000 -1 010 -1 001 0  011 0
001    011    001    011

001 0  000 0
001    000

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