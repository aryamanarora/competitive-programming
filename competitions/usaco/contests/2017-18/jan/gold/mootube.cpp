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
    int n;
    vi parent, size;

    disjoint_set(int N) : n(N), size(N), parent(N) {
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_union(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (b != a) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            size[b] = 0;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("mootube.in");
    ofstream cout("mootube.out");

    int n, q;
    cin >> n >> q;
    vector<pair<int, pair<bool, ii>>> c;
    for (int i = 0, p, q, r; i < n - 1; i++) {
        cin >> p >> q >> r;
        p--; q--;
        c.pb({r, {true, {p, q}}});
    }

    vii queries(q);
    map<ii, int> qq;
    for (auto &x : queries) {
        cin >> x.f >> x.s;
        x.s--;
        c.pb({x.f, {false, {x.s, x.s}}});
    }

    sort(c.rbegin(), c.rend());
    disjoint_set dsu(n);
    for (int i = 0; i < n; i++) dsu.make_set(i);

    for (auto &x : c) {
        if (x.s.f) dsu.make_union(x.s.s.f, x.s.s.s);
        else qq[{x.f, x.s.s.f}] = dsu.size[dsu.find_set(x.s.s.f)];
    }

    for (auto &x : queries) {
        cout << qq[{x.f, x.s}] - 1 << endl;
    }
}

/*
USE LONG LONG!!!!
*/