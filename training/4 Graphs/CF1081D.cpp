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

    int n, m, k;
    cin >> n >> m >> k;
    set<int> needed; int x;
    for (int i = 0; i < k; i++) {
        cin >> x;
        needed.insert(x);
    }

    vector<pair<int, ii>> edges(m);
    for (int i = 0; i < m; i++) cin >> edges[i].s.f >> edges[i].s.s >> edges[i].f;
    sort(edges.begin(), edges.end());

    for (int i = 0; i < m; i++) {
        needed.erase(edges[i].s.f);
        needed.erase(edges[i].s.s);
        if (needed.empty()) {
            for (int j = 0; j < k; j++) cout << edges[i].f << " ";
            cout << endl;
            return 0;
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