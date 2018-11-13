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

struct fake_disjoint_set {
    int n, sets;
    vi next;

    fake_disjoint_set(int N) : n(N), next(N) {
        for (int i = 0; i < N; i++) next[i] = i;
    }
    int find_set(int v) {
        if (v == next[v]) return v;
        return next[v] = find_set(next[v]);
    }
    void make_union(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (b != a) {
            next[b] = a;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l, r, x;
    cin >> n >> m;
    fake_disjoint_set dsu(n);
    vi winner(n, 0);

    while (m--) {
        cin >> l >> r >> x;
        l--; r--; x--;
        int pos = dsu.find_set(l), oldpos = pos;
        while (pos <= r) {
            pos = dsu.find_set(pos);
            dsu.make_union(x, oldpos);
            winner[oldpos] = x;
            if (pos == dsu.find_set(pos)) break;
            oldpos = pos;
        }
    }

    for (auto &x : winner) cout << x << " ";
    cout << endl;
}