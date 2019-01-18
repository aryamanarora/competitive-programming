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

    ifstream cin("lightson.in");
    ofstream cout("lightson.out");

    int n, m;
    cin >> n >> m;
    vector<vector<vii>> turn(n, vector<vii>(n));
    vector<vector<bool>> on(n, vb(n)), visited(n, vb(n)), reachable(n, vb(n));
    for (int i = 0, x, y, a, b; i < m; i++) {
        cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        turn[x][y].pb({a, b});
    }
    on[0][0] = true;
    reachable[0][0] = true;
    reachable[1][0] = true;
    reachable[0][1] = true;

    function<void(int, int)> dfs = [&](int x, int y) {
        if (visited[x][y]) return;
        visited[x][y] = true;
        // cerr << x + 1 << " " << y + 1 << endl;
        for (auto v : turn[x][y]) {
            on[v.f][v.s] = true;
            if (reachable[v.f][v.s]) dfs(v.f, v.s);
        }

        if (x > 0) {
            reachable[x - 1][y] = true;
            if (on[x - 1][y]) dfs(x - 1, y);
        }
        if (x < n - 1) {
            reachable[x + 1][y] = true;
            if (on[x + 1][y]) dfs(x + 1, y);
        }
        if (y > 0) {
            reachable[x][y - 1] = true;
            if (on[x][y - 1]) dfs(x, y - 1);
        }
        if (y < n - 1) {
            reachable[x][y + 1] = true;
            if (on[x][y + 1]) dfs(x, y + 1);
        }
    };

    dfs(0, 0);

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (on[i][j]) ans++;
    
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