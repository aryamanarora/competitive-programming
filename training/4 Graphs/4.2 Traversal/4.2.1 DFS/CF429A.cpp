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

vi ans, init, goal;
vector<vi> g;

void dfs(int u, int last, int depth, int even, int odd) {
    if (depth % 2) {
        if (init[u] == goal[u] and odd == 1) {
            ans.pb(u);
            odd = 0;
        }
        else if (init[u] != goal[u] and odd == 0) {
            ans.pb(u);
            odd = 1;
        }
    }
    else {
        if (init[u] == goal[u] and even == 1) {
            ans.pb(u);
            even = 0;
        }
        else if (init[u] != goal[u] and even == 0) {
            ans.pb(u);
            even = 1;
        }
    }

    for (auto v : g[u]) {
        if (v != last) dfs(v, u, depth + 1, even, odd);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, u, v;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    init.resize(n);
    goal.resize(n);
    for (int i = 0; i < n; i++) cin >> init[i];
    for (int i = 0; i < n; i++) cin >> goal[i];

    dfs(0, -1, 0, 0, 0);

    cout << ans.size() << endl;
    for (auto x : ans) cout << x + 1 << endl;
}

/*
USE LONG LONG!!!!
*/