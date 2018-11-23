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
    vi sum;

    segment_tree(int N, vi &s) : n(4 * N), sum(4 * N) {
        build(s, 1, 0, N - 1);
    };

    void build(vi &a, int v, int tl, int tr) {
        if (tl == tr) {
            sum[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);

            sum[v] = sum[v * 2] + sum[v * 2 + 1];
        }
    };

    int get_sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl and r == tr) {
            return sum[v];
        }

        int tm = (tl + tr) / 2;
        return get_sum(v * 2, tl, tm, l, min(r, tm)) + get_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void flip(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            sum[v] ^= 1;
        }
        else {
            int tm = (tl + tr) / 2;

            if (tm >= pos) flip(v * 2, tl, tm, pos);
            else flip(v * 2 + 1, tm + 1, tr, pos);
            
            sum[v] = sum[v * 2] + sum[v * 2 + 1];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vi a(n, 0);

    segment_tree segtree(n, a);

    char x; int l, r;
    while (k--) {
        cin >> x;
        if (x == 'F') {
            cin >> l;
            l--;
            segtree.flip(1, 0, n - 1, l);
        }
        else {
            cin >> l >> r;
            l--; r--;
            cout << segtree.get_sum(1, 0, n - 1, l, r) << endl;
        }
    }
}