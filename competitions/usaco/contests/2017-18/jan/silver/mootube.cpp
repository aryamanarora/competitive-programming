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

int query(int u, int par, int k, vector<vii> &g) {
    int res = 0;
    for (auto v : g[u]) {
        if (v.f != par and v.s >= k) res += (1 + query(v.f, u, k, g));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("mootube.in");
    ofstream cout("mootube.out");

    int n, q;
    cin >> n >> q;
    vector<vii> g(n);
    for (int i = 0, p, q, r; i < n - 1; i++) {
        cin >> p >> q >> r;
        p--; q--;
        g[p].pb({q, r});
        g[q].pb({p, r});
    }

    int k, v;
    while (q--) {
        cin >> k >> v;
        v--;
        cout << query(v, -1, k, g) << endl;
    }
}

/*
USE LONG LONG!!!!
*/