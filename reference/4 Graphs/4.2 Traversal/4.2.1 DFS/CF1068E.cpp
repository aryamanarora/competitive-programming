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

vector<vi> adj;
pair<bool, int> check;
pair<bool, int> dfs(int v, vector<bool> visited, int d) {
    visited[v] = true;
    int depth = -1;
    for (int &u : adj[v]) {
        if (!visited[u]) {
            check = dfs(u, visited, d + 1);
            if (check.f == false) return {false, -1};
            else if (depth == -1) depth = check.s;
            else if (depth != check.s) return {false, -1};
        }
    }
    return {true, d + depth};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, a, b;
    cin >> n >> k;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (auto &x : adj) {
        if (x.size() == 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (adj[i].size() != 1) {
            vector<bool> visited(n);
            check = dfs(i, visited, 0);
            if (check.f and check.s == k) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
}