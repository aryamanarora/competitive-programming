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

struct disjoint_set {
    int n, sets;
    vi parent;

    disjoint_set(int N) : n(N), sets(0), parent(N, -1) {}
    bool has(int v) {
        return (parent[v] != -1);
    }
    void make_set(int v) {
        parent[v] = v;
        sets++;
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_union(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (b != a) {
            parent[b] = a;
            sets--;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, k, a, nolang = 0;
    cin >> n >> m;
    disjoint_set dsu(m);

    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k == 0) {
            nolang++;
            continue;
        }
        int f;
        for (int i = 0; i < k; i++) {
            cin >> a; a--;
            if (i == 0) f = a;
            if (!dsu.has(a)) dsu.make_set(a);
            dsu.make_union(f, a);
        }
    }

    cout << nolang + (dsu.sets == 0 ? 0 : dsu.sets - 1) << endl;
}