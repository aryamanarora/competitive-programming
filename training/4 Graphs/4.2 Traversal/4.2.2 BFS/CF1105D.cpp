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

const vi dx = {1, -1, 0, 0};
const vi dy = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;
    cin >> n >> m >> p;
    vi speed(p); for (auto &x : speed) cin >> x;

    vector<queue<ii>> bfs(p);
    vector<vector<bool>> vis(n, vector<bool>(m));
    vi ans(p, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') vis[i][j] = true;
            else if (c != '.') {
                vis[i][j] = true;
                ans[c - '1']++;
                bfs[c - '1'].push({i, j});
            }
        }
    }

    auto okay = [&]() {
        for (auto &x : bfs) if (!x.empty()) return true;
        return false;
    };

    auto use = [&](int i, int j, int p) {
        // cout << i << " " << j << endl;
        if (i < 0 or j < 0 or i >= n or j >= m) return;
        if (vis[i][j]) return;
        vis[i][j] = true;
        ans[p]++;
        bfs[p].push({i, j});
    };

    while (okay()) {
        for (int i = 0; i < p; i++) {
            for (int turn = 0; turn < speed[i] and !bfs[i].empty(); turn++) {
                int x = bfs[i].size();
                while (x--) {
                    ii cur = bfs[i].front();
                    bfs[i].pop();
                    // cout << i << " " << turn << ": " << cur.f << " " << cur.s << endl;
                    for (int j = 0; j < 4; j++) use(cur.f + dx[j], cur.s + dy[j], i);
                }
            }
        }
    }

    for (auto &x : ans) cout << x << " ";
    cout << endl;
}

/*
USE LONG LONG!!!!

:pray: :fishy15:
:pray: :summitosity:
:pray: :prodakcin:

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