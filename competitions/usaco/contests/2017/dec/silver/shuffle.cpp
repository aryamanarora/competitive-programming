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

vi a;

void dfs(int u, int target, vector<bool> &in_cycle, vector<bool> &visited) {
    if (visited[u] and u == target) in_cycle[target] = true;
    if (visited[u]) return;
    if (in_cycle[u]) return;
    visited[u] = true;
    dfs(a[u], target, in_cycle, visited);
}

void dfs_cycle(int u, int target, vector<bool> &in_cycle) {
    if (u == target) return;
    in_cycle[u] = true;
    dfs_cycle(a[u], target, in_cycle);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("shuffle.in");
    ofstream cout("shuffle.out");

    int n;
    cin >> n;
    a.resize(n);
    vector<bool> in_cycle(n, false);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (a[i] == i) in_cycle[i] = true;
    }

    for (int i = 0; i < n; i++) {
        if (in_cycle[i]) continue;
        vector<bool> visited(n, false);
        dfs(i, i, in_cycle, visited);
        if (in_cycle[i]) {
            dfs_cycle(a[i], i, in_cycle);
        }
    }

    int ans = 0;
    for (auto x : in_cycle) if (x) ans++;

    cout << ans << endl;
}

/*
USE LONG LONG!!!!
*/