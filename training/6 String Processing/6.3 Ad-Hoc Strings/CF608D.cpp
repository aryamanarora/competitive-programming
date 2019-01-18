// ITS WRONG USE DP

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
    vi a(n); for (auto &x : a) cin >> x;

    int ans = 0;
    while (a.size() > 0) {
        int maxlen = 0, l, r;
        ans++;
        for (int i = 0; i < n; i++) {
            int l1 = i, r1 = i;
            for (int j = 1; i + j < n and i - j >= 0; j++) {
                if (a[i + j] == a[i - j]) {
                    l1--;
                    r1++;
                }
                else break;
            }
            if (r1 - l1 + 1 > maxlen) {
                maxlen = r1 - l1 + 1;
                l = l1; r = r1;
            }
            
            l1 = i + 1, r1 = i;
            for (int j = 0; i + j + 1 < n and i - j >= 0; j++) {
                if (a[i - j] == a[i + j + 1]) {
                    l1--;
                    r1++;
                }
                else break;
            }
            if (r1 - l1 + 1 > maxlen) {
                maxlen = r1 - l1 + 1;
                l = l1; r = r1;
            }
        }

        a.erase(a.begin() + l, a.begin() + r + 1);
        n = a.size();
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