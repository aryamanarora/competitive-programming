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

    int n, m, k, p;
    cin >> n >> m >> k >> p;
    vector<vl> a(n, vl(m));
    vl r(n), c(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }

    priority_queue<int> rr, cc;
    for (auto x : r) rr.push(x);
    for (auto x : c) cc.push(x);

    vl rows(k + 1, 0), cols(k + 1, 0);
    for (int i = 0; i < k; i++) {
        int rrr = rr.top(), ccc = cc.top();
        rows[i + 1] = rrr;
        rr.pop();
        rr.push(rrr - (p * m));
        
        cols[i + 1] = ccc;
        cc.pop();
        cc.push(ccc - (p * n));
    }

    for (int i = 1; i <= k; i++) {
        cols[i] += cols[i - 1];
        rows[i] += rows[i - 1];
    }

    ll ans = numeric_limits<ll>::min();
    for (int i = 0; i <= k; i++) {
        ans = max(ans, cols[i] + rows[k - i] - (1LL * (i) * (k - i) * p));
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