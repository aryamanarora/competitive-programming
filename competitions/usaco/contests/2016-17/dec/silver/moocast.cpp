/*
ID: aryaman4
TASK: square
LANG: C++14
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

struct cow {
    int x, y, p;
};

int dfs(int v, vector<bool> &visited, const vector<vi> &g) {
    if (visited[v]) return 0;
    visited[v] = true;
    int ct = 1;
    for (auto u : g[v]) {
        ct += dfs(u, visited, g);     
    }
    return ct;
}

double dist(cow a, cow b) {
    return sqrt(abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    int n;
    fin >> n;
    vector<cow> a(n);
    for (int i = 0; i < n; i++)
        fin >> a[i].x >> a[i].y >> a[i].p;

    vector<vi> graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (dist(a[i], a[j]) <= (double) a[i].p) {
                graph[i].pb(j);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        ans = max(ans, dfs(i, visited, graph));
    }
    fout << ans << endl;
}