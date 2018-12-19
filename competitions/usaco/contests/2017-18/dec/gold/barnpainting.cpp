/*
ID: aryaman4
TASK: barnpainting
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
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

const ll MOD = 1000000007;

void dfs(int v, vector<vi> &g, vector<bool> &visited, vector<array<ll, 4>> &dp) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u]) {
            dfs(u, g, visited, dp);
            dp[v][0] *= ((dp[u][1] + dp[u][2]) % MOD);
            dp[v][0] %= MOD;
            dp[v][1] *= ((dp[u][0] + dp[u][2]) % MOD);
            dp[v][1] %= MOD;
            dp[v][2] *= ((dp[u][0] + dp[u][1]) % MOD);
            dp[v][2] %= MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("barnpainting.in");
    ofstream fout("barnpainting.out");

    int n, k, a, b;
    fin >> n >> k;
    vector<vi> g(n);
    vector<array<ll, 4>> dp(n, array<ll, 4>({1, 1, 1}));
    for (int i = 0; i < n - 1; i++) {
        fin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < k; i++) {
        fin >> a >> b;
        a--; b--;
        dp[a] = {0, 0, 0};
        dp[a][b] = 1;
    }
    
    vector<bool> visited(n, false);
    dfs(0, g, visited, dp);

    fout << (dp[0][0] + dp[0][1] + dp[0][2]) % MOD << endl;
}