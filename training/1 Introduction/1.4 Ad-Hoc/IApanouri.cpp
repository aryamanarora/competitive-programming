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

    ifstream cin("panouri.in");
    ofstream cout("panouri.out");

    int n, t, b;
    cin >> n >> t;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<bool> us(n, false);
    for (int i = 0; i < t; i++) {
        cin >> b;
        us[b] = true;
    }

    // competitor's billboard numbers don't matter, make all 0
    for (int i = 0; i < n; i++) if (!us[a[i]]) a[i] = 0;

    // sliding window technique
    int start = 0, end = 0;
    vi cur(n, 0); int ct = 0;
    cur[a[0]]++;
    if (a[0] != 0) ct++;
    int ans = -1;
    while (start != n - 1) {
        /*
        cerr << ct << ": ";
        for (int i = start; i <= end; i++) cerr << a[i] << " ";
        cerr << endl;
        */

        // if interval contains all our billboards
        if (ct >= t) {
            if (ans == -1) ans = end - start;
            else ans = min(ans, end - start);
            if (a[start] == -1 or cur[a[start]] > 1) {
                cur[a[start]]--;
                if (a[start] != 0 and cur[a[start]] == 0) ct--;
                start++;
            }
            else {
                if (end != n - 1) {
                    end++;
                    cur[a[end]]++;
                    if (a[end] != 0 and cur[a[end]] == 1) ct++;
                }
                else {
                    cur[a[start]]--;
                    if (a[start] != 0 and cur[a[start]] == 0) ct--;
                    start++;
                }
            }
        }
        else if (ct < t) {
            if (end != n - 1) {
                end++;
                cur[a[end]]++;
                if (a[end] != 0 and cur[a[end]] == 1) ct++;
                if (a[start] == 0) {
                    cur[a[start]]--;
                    if (a[start] != 0 and cur[a[start]] == 0) ct--;
                    start++;
                }
            }
            else {
                cur[a[start]]--;
                if (a[start] != 0 and cur[a[start]] == 0) ct--;
                start++;
            }
        }
    }

    if (ct >= t) {
        if (ans == -1) ans = end - start;
        else ans = min(ans, end - start);
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