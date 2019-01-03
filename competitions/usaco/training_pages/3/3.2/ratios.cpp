/*
ID: aryaman4
TASK: ratios
LANG: C++14
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

const int INF = numeric_limits<int>::max();

bool checkdiv(int a, int b) {
    if (a == 0 and b == 0) return true;
    if (a == 0 or b == 0) return false;
    return (a % b ? false : true);
}

bool cmp(int a, int b, int c, int d) {
    int res1 = (b == 0 ? 0 : a / b);
    int res2 = (d == 0 ? 0 : c / d);
    if (res1 == 0 or res2 == 0) return true;
    return (res1 == res2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("ratios.in");
    ofstream cout("ratios.out");

    array<int, 3> a, b, c, d, res;
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    cin >> c[0] >> c[1] >> c[2];
    cin >> d[0] >> d[1] >> d[2];

    int ans = INF, l, m, n;

    for (int i = 0; i <= 100; i++) {
        res[0] += i * b[0];
        res[1] += i * b[1];
        res[2] += i * b[2];
        for (int j = 0; j <= 100; j++) {
            res[0] += j * c[0];
            res[1] += j * c[1];
            res[2] += j * c[2];
            for (int k = 0; k <= 100; k++) {
                res[0] += k * d[0];
                res[1] += k * d[1];
                res[2] += k * d[2];
                if (checkdiv(res[0], a[0]) and checkdiv(res[1], a[1]) and checkdiv(res[2], a[2])) {
                    if (cmp(res[0], a[0], res[1], a[1]) and cmp(res[1], a[1], res[2], a[2])) {
                        if (res[0] / a[0] < ans) {
                            ans = res[0] / a[0];
                            l = i; m = j; n = k;
                        }
                    }
                }
                res[0] -= k * d[0];
                res[1] -= k * d[1];
                res[2] -= k * d[2];
            }
            res[0] -= j * c[0];
            res[1] -= j * c[1];
            res[2] -= j * c[2];
        }
        res[0] -= i * b[0];
        res[1] -= i * b[1];
        res[2] -= i * b[2];
    }

    if (ans != INF) cout << l << " " << m << " " << n << " " << ans << endl;
    else cout << "NONE" << endl;
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