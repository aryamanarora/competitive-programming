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
    vi parent;

    disjoint_set(int N) : n(N), parent(N) {}
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
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    disjoint_set rig(n);
    for (int i = 0; i < n; i++) rig.make_set(i);

    vi ans(n, -1);
    for (int i, l, r, x; i < m; i++) {
        cin >> l >> r >> x;
        l--, r--, x--;
        for (int j = l, i; j <= r;) {
            if (j == x) {j++; continue;}
            if (ans[j] == -1) ans[j] = x;
            if (j == n - 1) break;
            i = j;
            j = rig.find_set(j + 1);
            rig.make_union(j, i);
        }
        // for (int i = 0; i < n; i++) cout << rig.parent[i] << " ";
        // cout << endl;
        // for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
        // cout << endl;
    }

    for (auto &x : ans) cout << x + 1 << " ";
    cout << endl;
}