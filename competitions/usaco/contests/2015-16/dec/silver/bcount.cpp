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
typedef vector<bool> vb;

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;

typedef vector<vi> vvi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("bcount.in");
    ofstream cout("bcount.out");

    int n, q;
    cin >> n >> q;
    vector<array<int, 3>> prefixsum(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x; x--;
        prefixsum[i][x]++;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) prefixsum[i][j] += prefixsum[i - 1][j];
    }

    for (int i = 0, a, b; i < q; i++) {
        cin >> a >> b;
        a--, b--;
        for (int j = 0; j < 3; j++) {
            if (a == 0) cout << prefixsum[b][j];
            else cout << prefixsum[b][j] - prefixsum[a - 1][j];
            if (j != 2) cout << " ";
            else cout << endl;
        }
    }
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