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

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int n, m;

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};
string dir = "RLDU";

string path = "";
bool done = false;
void dfs(ii u, ii p, int d, vector<string> &a, vector<vi> &dist) {
    if (u.f == 0 or u.f == n - 1 or u.s == 0 or u.s == m - 1) {
        done = true;
        cout << "YES" << endl;
        cout << d << endl;
        cout << path << endl;
        return;
    }
    for (int i = 0; i < 4 and !done; i++) {
        int x = u.f + dx[i], y = u.s + dy[i];
        if (x < 0 or x >= n or y < 0 or y >= m) continue;
        if (a[x][y] == '#') continue;
        if (x == p.f and y == p.s) continue;
        if (d + 1 < dist[x][y]) {
            path += dir[i];
            dfs({x, y}, u, d + 1, a, dist);
            path.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    queue<pair<ii, int>> bfs;
    ii start;
    vector<string> a(n);
    vector<vi> dist(n, vi(m, numeric_limits<int>::max()));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'M') {
                bfs.push({{i, j}, 0});
                dist[i][j] = 0;
            }
            else if (a[i][j] == 'A') start = {i, j};
        }
    }

    auto move = [&](int x, int y, int d) {
        if (x < 0 or x >= n or y < 0 or y >= m) return;
        if (a[x][y] == '#') return;
        if (d < dist[x][y]) {
            dist[x][y] = d;
            bfs.push({{x, y}, d});
        }
    };

    while (!bfs.empty()) {
        int x = bfs.front().f.f, y = bfs.front().f.s, d = bfs.front().s;
        bfs.pop();
        if (d > dist[x][y]) continue;
        for (int i = 0; i < 4; i++) {
            move(x + dx[i], y + dy[i], d + 1);
        }
    }

    dfs(start, {-1, -1}, 0, a, dist);
    if (!done) cout << "NO" << endl;
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