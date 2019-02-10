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

const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vl a(n); for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    ll ans = 0, sum = 1;
    for (int i = 0; i < n; i++) {
        // cout << "+ " << (sum - 1) << " * " << a[i] << endl;
        // cout << "- " << (sum - 1) << " * " << a[n - i - 1] << endl;
        ans += (sum - 1) * a[i];
        ans %= MOD;
        sum *= 2;
        if (sum >= MOD) sum -= MOD;
    }
    sum = 1;
    for (int i = 0; i < n; i++) {
        ll sub = (sum - 1) * a[n - i - 1];
        sub %= MOD;
        ans -= sub;
        if (ans < 0) ans += MOD;
        sum *= 2;
        if (sum >= MOD) sum -= MOD;
    }
    cout << ans << endl;
}

/*
1 34    9
0100122101
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