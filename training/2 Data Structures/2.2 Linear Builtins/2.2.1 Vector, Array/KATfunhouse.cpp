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

vi dx = {1, 0, -1, 0};
vi dy = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int w, l, ct = 1;
    while (cin >> w >> l) {
        if (w == 0 and l == 0) break;
        vector<string> a(l);
        int x, y;
        for (int i = 0; i < l; i++) {
            cin >> a[i];
            if (a[i].find('*') != string::npos) {
                x = a[i].find('*');
                y = i;
            }
        }
        int dir;
        if (x == 0) dir = 0;
        else if (x == w - 1) dir = 2;
        else if (y == 0) dir = 3;
        else dir = 1;

        do {
            x += dx[dir], y += dy[dir];
            if (a[y][x] == '/') {
                if (dir == 0) dir = 1;
                else if (dir == 1) dir = 0;
                else if (dir == 2) dir = 3;
                else dir = 2;
            }
            else if (a[y][x] == '\\') {
                if (dir == 0) dir = 3;
                else if (dir == 1) dir = 2;
                else if (dir == 2) dir = 1;
                else dir = 0;
            }
        } while ((x != 0 and x != w - 1) and (y != 0 and y != l - 1));

        a[y][x] = '&';

        cout << "HOUSE " << ct << endl;
        for (auto &x : a) {
            for (auto &y : x) cout << y;
            cout << endl;
        }
        ct++;
    }
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