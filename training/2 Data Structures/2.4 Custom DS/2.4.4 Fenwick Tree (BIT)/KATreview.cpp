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

template<typename T>
T least_significant_one(T x) {
    return (x & (-x));
}

struct fenwick_tree {
    int n;
    vl freq;
    fenwick_tree(int N) : n(N), freq(N + 1, 0) {};
    ll sum(int a) {
        ll res = 0;
        for (; a; a -= least_significant_one(a)) res += freq[a];
        return res;
    }
    void add(int a, int v) {
        for (; a <= n; a += least_significant_one(a)) freq[a] += v;
    }
};

struct employee {
    int manager, rank, time;
};

fenwick_tree bit(100001);

void dfs(int u, vector<employee> &a, vector<vi> &g, vl &ans) {
    ll orig = bit.sum(a[u].rank - 1);
    for (auto v : g[u]) dfs(v, a, g, ans);
    ans[u] += bit.sum(a[u].rank - 1) - orig;
    bit.add(a[u].rank, a[u].time);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<employee> a(n); vector<vi> g(n);
    int ct = 0, root;
    for (auto &[m, r, t] : a) {
        cin >> m >> r >> t;
        m--;
        if (m == -2) root = ct;
        else g[m].pb(ct);
        ct++;
    }

    vl ans(n);
    dfs(root, a, g, ans);

    for (auto x : ans) cout << x << endl;
}

/*
4 4 80
1 1 40
-1 10 60
3 5 50
4 8 70
*/