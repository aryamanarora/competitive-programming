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

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};
string dir = "DURL";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    ii start, end;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') start = {i, j};
            else if (a[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<ii, int>> bfs;
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vii> last(n, vii(m));
    bfs.push({start, 0});
    int ans;
    while (!bfs.empty()) {
        int x = bfs.front().f.f, y = bfs.front().f.s;
        int d = bfs.front().s;
        if (mp(x, y) == end) {
            ans = d;
            break;
        }
        bfs.pop();
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] >= 0 and x + dx[i] < n and y + dy[i] >= 0 and y + dy[i] < m) {
                if (!vis[x + dx[i]][y + dy[i]] and a[x + dx[i]][y + dy[i]] != '#') {
                    bfs.push({{x + dx[i], y + dy[i]}, d + 1});
                    vis[x + dx[i]][y + dy[i]] = true;
                    last[x + dx[i]][y + dy[i]] = {x, y};
                }
            }
        }
    }

    if (vis[end.f][end.s]) {
        cout << "YES" << endl;
        cout << ans << endl;
        string dirs;
        while (end != start) {
            for (int i = 0; i < 4; i++) {
                if (mp(last[end.f][end.s].f + dx[i], last[end.f][end.s].s + dy[i]) == end) {
                    dirs += dir[i];
                    end = last[end.f][end.s];
                    break;
                }
            }
        }
        reverse(dirs.begin(), dirs.end());
        cout << dirs << endl;
    }
    else cout << "NO" << endl;
}

/*
USE LONG LONG!!!!

205
100->5

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