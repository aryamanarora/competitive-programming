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

set<int> ans;
map<int, int> a, b;

void dfs(int depth, int ma, int mb) {
    if (depth == 4) ans.insert(ma);
    else if (depth % 2 == 0) {
        for (auto &x : a) {
            if (x.s != 0) {
                x.s--;
                b[x.f]++;
                dfs(depth + 1, ma - x.f, mb + x.f);
                x.s++;
                b[x.f]--;
            }
        }
    }
    else {
        for (auto &x : b) {
            if (x.s != 0) {
                x.s--;
                a[x.f]++;
                dfs(depth + 1, ma + x.f, mb - x.f);
                x.s++;
                a[x.f]--;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("backforth.in");
    ofstream cout("backforth.out");

    int x;
    for (int i = 0; i < 10; i++) {
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < 10; i++) {
        cin >> x;
        b[x]++;
    }

    dfs(0, 1000, 1000);
    cout << ans.size() << endl;
    // for (auto x : ans) cerr << x << endl;
}

/*
USE LONG LONG!!!!

Monday: 1000 1000


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