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

    int n, m, r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;
    r--, c--;
    vector<string> g(n); for (auto &x : g) cin >> x;

    auto is_free = [&](int r, int c) {
        if (r >= n or r < 0 or c >= m or c < 0) return false;
        return (g[r][c] == '.');
    };

    vector<vector<int>> dist(n, vi(m, INT_MAX));
    dist[r][c] = 0;
    deque<ii> bfs;
    bfs.push_front({r, c});
    while (!bfs.empty()) {
        ii cur = bfs.front(); bfs.pop_front();
        if (is_free(cur.f, cur.s + 1)) {
            if (dist[cur.f][cur.s] < dist[cur.f][cur.s + 1]) {
                dist[cur.f][cur.s + 1] = dist[cur.f][cur.s];
                bfs.push_front({cur.f, cur.s + 1});
            }
        }
        if (is_free(cur.f, cur.s - 1)) {
            if (dist[cur.f][cur.s] < dist[cur.f][cur.s - 1]) {
                dist[cur.f][cur.s - 1] = dist[cur.f][cur.s];
                bfs.push_front({cur.f, cur.s - 1});
            }
        }
        if (is_free(cur.f + 1, cur.s - 1))
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