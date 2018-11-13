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

struct segment_tree {
    int n;
    vi sum, maxi;

    segment_tree(int N, vi &s) : n(4 * N), sum(4 * N), maxi(4 * N) {
        build(s, 1, 0, N - 1);
    };

    void build(vi &a, int v, int tl, int tr) {
        if (tl == tr) {
            maxi[v] = sum[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);

            maxi[v] = max(maxi[v * 2], maxi[v * 2 + 1]);
            sum[v] = sum[v * 2] + sum[v * 2 + 1];
        }
    };

    int get_max(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl and r == tr) {
            return maxi[v];
        }

        int tm = (tl + tr) / 2;
        return max(
            get_max(v * 2, tl, tm, l, min(r, tm)),
            get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    };

    int get_sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl and r == tr) {
            return sum[v];
        }

        int tm = (tl + tr) / 2;
        return get_sum(v * 2, tl, tm, l, min(r, tm)) + get_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update_max(int v, int tl, int tr, int inc) {
        if (tl == tr) {
            maxi[v] += inc;
            sum[v] += inc; 
        }
        else {
            int tm = (tl + tr) / 2;

            if (maxi[v * 2] == maxi[1]) update_max(v * 2, tl, tm, inc);
            if (maxi[v * 2 + 1] == maxi[1]) update_max(v * 2 + 1, tm + 1, tr, inc);
            
            maxi[v] = max(maxi[v * 2], maxi[v * 2 + 1]);
            sum[v] = sum[v * 2] + sum[v * 2 + 1];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    segment_tree segtree(n, a);
    
    int q;
    cin >> q;
    char x;
    int l, r;
    while (q--) {
        cin >> x;
        if (x == 'I') {
            cin >> l;
            segtree.update_max(1, 0, n - 1, l);
        }
        else if (x == 'M') {
            cin >> l >> r;
            l--; r--;
            cout << segtree.get_max(1, 0, n - 1, l, r) << endl;
        }
        else {
            cin >> l >> r;
            l--; r--;
            cout << segtree.get_sum(1, 0, n - 1, l, r) << endl;
        }
    }
}