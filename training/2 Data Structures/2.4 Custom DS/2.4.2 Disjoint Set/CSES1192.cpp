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

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};
int n, m;

void dfs(vector<vector<bool>> &vis, vector<string> &a, int x, int y) {
    if (x < 0 or x >= n or y < 0 or y >= m) return;
    if (a[x][y] == '#' or vis[x][y]) return;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        dfs(vis, a, x + dx[i], y + dy[i]);
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<string> a(n); for (auto &x : a) cin >> x;
    vector<vector<bool>> vis(n, vector<bool>(m));

    int ans = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (a[x][y] == '.' and !vis[x][y]) {
                ans++;
                dfs(vis, a, x, y);
            }
        }
    }
    cout << ans << endl;
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