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

    int n, h;
    cin >> n >> h;
    vi bottom(n / 2), top(n / 2);
    for (int i = 0; i < n; i++) {
        if (i % 2) cin >> top[i / 2];
        else cin >> bottom[i / 2];
    }
    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    vi bottomh(h + 1), toph(h + 1);
    bottomh[0] = toph[h] = n / 2;
    for (auto &x : bottom) if (x != h) bottomh[x + 1]--;
    for (auto &x : top) if (x != 0) toph[h - x]--;
    partial_sum(bottomh.begin(), bottomh.end(), bottomh.begin());
    partial_sum(toph.rbegin(), toph.rend(), toph.rbegin());
    
    int mini = n, ct = 1;
    for (int i = 1; i <= h; i++) {
        if (toph[i] + bottomh[i] < mini) {
            mini = toph[i] + bottomh[i];
            ct = 1;
        }
        else if (toph[i] + bottomh[i] == mini) ct++;
    }
    
    cout << mini << " " << ct << endl;
}

/*
USE LONG LONG!!!!

1 3 5 1 3 5
      | | |
      | |
    | | |
    | |
  | | |
  | |
| | |

3 2 2 1 1 0 0
0 0 1 1 2 2 3
3 2 3 2 3 2 3

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