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

    ifstream cin("hps.in");
    ofstream cout("hps.out");

    int n;
    cin >> n;
    string a;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a.pb(c);
    }

    vector<vi> pre(n, vi(3)), suf(n, vi(3));
    for (int i = 0; i < n; i++) {
        pre[i][0] += (i > 0 ? pre[i - 1][0] : 0) + (a[i] == 'H');
        pre[i][1] += (i > 0 ? pre[i - 1][1] : 0) + (a[i] == 'P');
        pre[i][2] += (i > 0 ? pre[i - 1][2] : 0) + (a[i] == 'S');
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i][0] += (i < n - 1 ? suf[i + 1][0] : 0) + (a[i] == 'H');
        suf[i][1] += (i < n - 1 ? suf[i + 1][1] : 0) + (a[i] == 'P');
        suf[i][2] += (i < n - 1 ? suf[i + 1][2] : 0) + (a[i] == 'S');
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) ans = max(ans, pre[i - 1][j] + suf[i][k]);
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