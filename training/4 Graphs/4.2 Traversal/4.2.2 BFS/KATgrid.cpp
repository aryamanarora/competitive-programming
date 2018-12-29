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
    ll n, m;
    cin >> n >> m;
    vector<vi> grid(n, vi(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j] - '0';
        }
    }
    vector<vi> dist(n, vi(m, 1000000000));
    queue<pair<ii, int>> bfs;
    bfs.push({{0, 0}, 0});
    while (!bfs.empty()) {
        pair<ii, int> cur = bfs.front();
        bfs.pop();
        if (cur.f.f == n - 1 and cur.f.s == m - 1) {
            cout << cur.s << endl;
            return 0;
        }
        if (cur.s < dist[cur.f.f][cur.f.s]) {
            int d = grid[cur.f.f][cur.f.s];
            dist[cur.f.f][cur.f.s] = cur.s;
            if (cur.f.f + d < n) bfs.push({{cur.f.f + d, cur.f.s}, cur.s + 1});
            if (cur.f.f - d >= 0) bfs.push({{cur.f.f - d, cur.f.s}, cur.s + 1});
            if (cur.f.s + d < m) bfs.push({{cur.f.f, cur.f.s + d}, cur.s + 1});
            if (cur.f.s - d >= 0) bfs.push({{cur.f.f, cur.f.s - d}, cur.s + 1});
        }
    }
    cout << -1 << endl;
}