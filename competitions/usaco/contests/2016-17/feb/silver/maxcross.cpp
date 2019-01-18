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

    ifstream cin("maxcross.in");
    ofstream cout("maxcross.out");

    int n, k, b;
    cin >> n >> k >> b;

    vector<bool> a(n, true);
    for (int i = 0, x; i < b; i++) {
        cin >> x;
        x--;
        a[x] = false;
    }

    vi prefixsum(n, 0);
    for (int i = 0; i < n; i++) {
        if (i > 0) prefixsum[i] = prefixsum[i - 1];
        if (!a[i]) prefixsum[i]++;
        // cerr << prefixsum[i] << " ";
    }
    // cerr << endl;

    int ans = prefixsum[k - 1];
    // cerr << prefixsum[k - 1] << " ";
    for (int i = k; i < n; i++) {
        ans = min(ans, prefixsum[i] - prefixsum[i - k]);
        // cerr << prefixsum[i] - prefixsum[i - k] << " ";
    }
    // cerr << endl;
    
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