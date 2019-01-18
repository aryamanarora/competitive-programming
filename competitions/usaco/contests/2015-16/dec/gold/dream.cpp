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

struct pos {
    int x, y, dist, d;
    bool orange, sliding;
};

vi dx = {1, -1, 0, 0},
   dy = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("dream.in");
    ofstream cout("dream.out");

    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (auto &x : a) {
        for (auto &y : x) cin >> y;
    }
    cerr << "k\n";

    bool vis[1001][1001][2][5] = {false};
    queue<pos> bfs;
    bfs.push({0, 0, 0, 0, false, false});
    cerr << "k\n";

    auto is_valid = [&](pos &p) {
        if (!(p.x >= 0 and p.x < n and p.y >= 0 and p.y < m)) return false;
        if (vis[p.x][p.y][p.orange][p.d]) return false;
        if (a[p.x][p.y] == 0) return false;
        if (a[p.x][p.y] == 3 and !p.orange) return false;
        return true;
    };

    auto move = [&](const pos &cur, int d) {
        pos next = {cur.x + dx[d], cur.y + dy[d], cur.dist + 1, d, cur.orange, cur.sliding};
        if (cur.sliding) {
            pos req = {cur.x + dx[cur.d], cur.y + dy[cur.d], cur.dist + 1, cur.d, cur.orange, cur.sliding};
            if (!is_valid(req)) {
                next.sliding = false;
            }
            else if (d != cur.d) return;
        }
        cerr << next.x << " " << next.y << ": " << is_valid(next) << endl;
        if (!is_valid(next)) return;
        if (a[next.x][next.y] == 2) next.orange = true;
        if (a[next.x][next.y] == 4) {next.orange = false; next.sliding = true;}

        bfs.push(next);
    };

    while (!bfs.empty()) {
        pos cur = bfs.front(); bfs.pop();
        if (cur.x == n - 1 and cur.y == m - 1) {
            cout << cur.dist << endl;
            return 0;
        }

        vis[cur.x][cur.y][cur.orange][(cur.sliding ? cur.d : 4)] = true;

        cerr << cur.x << " " << cur.y << " from " << cur.x - dx[cur.d] << " " << cur.y - dy[cur.d] << endl;

        for (int i = 0; i < 4; i++) {
            move(cur, i);
        }
    }

    cout << -1 << endl;
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

1-------
       8
---4
--3
*/