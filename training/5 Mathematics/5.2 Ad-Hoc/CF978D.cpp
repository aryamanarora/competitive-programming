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

    int n;
    cin >> n;
    vi b(n);
    for (auto &x : b) cin >> x;
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = -1;

    for (int k = -1; k <= 1; k++) {
        for (int j = -1; j <= 1; j++) {
            int ct = (abs(k) + abs(j)); bool okay = true;
            vi a(b.begin(), b.end());
            a[0] += k; a[1] += j;
            for (int i = 2; i < n; i++) {
                if ((a[i] - a[i - 1]) - (a[1] - a[0]) == 1) {
                    ct++;
                    a[i]--;
                }
                else if ((a[i] - a[i - 1]) - (a[1] - a[0]) == -1) {
                    ct++;
                    a[i]++;
                }
                else if (abs((a[i] - a[i - 1]) - (a[1] - a[0])) > 1) {
                    okay = false;
                    break;
                }
            }
            if (okay) ans = (ans == -1 ? ct : min(ans, ct));
        }
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
*/