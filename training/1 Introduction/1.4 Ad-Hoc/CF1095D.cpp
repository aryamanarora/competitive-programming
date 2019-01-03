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

    int n;
    cin >> n;
    vii a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
        x--; y--;
    }

    vi ans(n + 5);
    ans[0] = 0;
    vector<bool> done(n);
    done[0] = true;
    for (int i = 0, ct = 0; ct < n; ct++) {
        int x = a[i].f, y = a[i].s;
        if (done[y]) {
            ans[ct + 1] = x;
            i = x;
        }
        else if (done[x]) {
            ans[ct + 1] = y;
            i = y;
        }
        else if (a[x].f == y or a[x].s == y) {
            ans[ct + 1] = x;
            done[x] = true;
            i = x;
        }
        else {
            ans[ct + 1] = y;
            done[y] = true;
            i = y;
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
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