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

int dfs(int u, int parent, vector<vi> &g) {
    for (auto v : g[u]) if (v != parent) return dfs(v, u, g);
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vi> g(n); int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (g[i].size() > 2) {
            if (root == -1) root = i;
            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if (root == -1) root = 0;

    cout << "Yes" << endl << g[root].size() << endl;
    for (auto v : g[root]) {
        cout << root + 1 << " " << dfs(v, root, g) + 1 << endl;
    }
}

/*
USE LONG LONG!!!!
*/