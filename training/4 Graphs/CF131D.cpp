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

const int MAX = 3005;

vi g[MAX];
int child[MAX] = {-1};
bool visited[MAX] = {false};
bool cycle_found = false; int cycle;

void dfs(int u, int last) {
    if (visited[u]) {
        cycle = u;
        cycle_found = true;
        return;
    }
    visited[u] = true;
    if (!cycle_found) {
        for (auto v : g[u]) {
            if (v != last) {
                child[u] = v;
                dfs(v, u);
                if (cycle_found) return;
            }
        }
    }
    child[u] = -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> q;
        p--; q--;
        g[p].pb(q);
        g[q].pb(p);
    }
    dfs(0, -1);

    vi dist(n, -1);

    int u = cycle;
    do {
        // cout << u << " ";
        dist[u] = 0;
        u = child[u];
    } while (u != cycle);
    // cout << endl;

    do {
        queue<ii> bfs;
        bfs.push({u, 0});
        while (!bfs.empty()) {
            ii u = bfs.front();
            bfs.pop();
            dist[u.f] = u.s;
            for (auto v : g[u.f]) if (dist[v] == -1) bfs.push({v, u.s + 1});
        }
        u = child[u];
    } while (u != cycle);

    for (int u = 0; u < n; u++) cout << dist[u] << " ";
    cout << endl;
}

/*
USE LONG LONG!!!!
*/