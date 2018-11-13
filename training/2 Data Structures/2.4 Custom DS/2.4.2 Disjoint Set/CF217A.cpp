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

    disjoint_set(int N) : n(N), sets(N) {
        parent.resize(N);
    }
    void make_set(int v) {
        parent[v] = v;
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

    int n, x, y;
    cin >> n;
    vii coords;
    disjoint_set dsu(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coords.pb(mp(x, y));
        dsu.make_set(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (coords[i].f == coords[j].f or coords[i].s == coords[j].s) {
                dsu.make_union(i, j);
            }
        }
    }

    cout << dsu.sets << endl;
}