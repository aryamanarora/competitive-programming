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

int n, m, k, keepct = 0, ct = 0;
vector<set<int>> graph;
vii key;

void dfs(int v, vector<bool> &visited, vector<vi> &a) {
    if (visited[v] or keepct == ct - k) return;
    visited[v] = true;
    a[key[v].f][key[v].s] = -2;
    keepct++;
    for (auto u : graph[v]) dfs(u, visited, a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    char x;
    vector<vi> a(n, vi(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (x == '.') {
                a[i][j] = ct;
                set<int> cur;
                if (i > 0 and a[i - 1][j] != -1) {
                    cur.insert(a[i - 1][j]);
                    graph[a[i - 1][j]].insert(ct);
                }
                if (j > 0 and a[i][j - 1] != -1) {
                    cur.insert(a[i][j - 1]);
                    graph[a[i][j - 1]].insert(ct);
                }
                graph.pb(cur);
                key.pb({i, j});
                ct++;
            }
        }
    }
    
    vector<bool> visited(ct, false);
    dfs(0, visited, a);

    for (auto x : a) {
        for (auto y : x) {
            if (y == -2) cout << '.';
            else if (y == -1) cout << '#';
            else cout << 'X';
        }
        cout << endl;
    }
}