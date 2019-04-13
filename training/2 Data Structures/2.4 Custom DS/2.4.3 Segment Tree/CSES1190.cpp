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

const ll INF = -1000000;
const int MAX = 100005;

struct node {
    ll pref, suf, total, sub;
};

struct segment_tree {
    int n;
    vector<node> maxi;

    segment_tree(int N, vi &s) : n(4 * N), maxi(4 * N, node({0, 0, 0, 0})) {
        build(s, 1, 0, N - 1);
    };

    void build(vi &a, int v, int tl, int tr) {
        if (tl == tr) {
            maxi[v] = {a[tl], a[tl], a[tl], a[tl]};
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);

            maxi[v] = {
                max(maxi[v * 2].pref, maxi[v * 2].total + maxi[v * 2 + 1].pref),
                max(maxi[v * 2 + 1].suf, maxi[v * 2 + 1].total + maxi[v * 2].suf),
                maxi[v * 2].total + maxi[v * 2 + 1].total,
                max(max(maxi[v * 2].sub, maxi[v * 2 + 1].sub), maxi[v * 2].suf + maxi[v * 2 + 1].pref)
            };
        }
    };

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            maxi[v] = {val, val, val, val};
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v * 2, tl, tm, pos, val);
            else update(v * 2 + 1, tm + 1, tr, pos, val);

            maxi[v] = {
                max(maxi[v * 2].pref, maxi[v * 2].total + maxi[v * 2 + 1].pref),
                max(maxi[v * 2 + 1].suf, maxi[v * 2 + 1].total + maxi[v * 2].suf),
                maxi[v * 2].total + maxi[v * 2 + 1].total,
                max(max(maxi[v * 2].sub, maxi[v * 2 + 1].sub), maxi[v * 2].suf + maxi[v * 2 + 1].pref)
            };
        }
    }

    node get_max(int v, int tl, int tr, int l, int r) {
        if (l > r) return node{INF, INF, 0, INF};
        if (l == tl and r == tr) {
            return maxi[v];
        }

        int tm = (tl + tr) / 2;
        node left = get_max(v * 2, tl, tm, l, min(r, tm)),
             right = get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

        return node{
            max(left.pref, left.total + right.pref),
            max(right.suf, right.total + left.suf),
            left.total + right.total,
            max(max(left.sub, right.sub), left.suf + right.pref)
        };
    };
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vi a(n); for (auto &x : a) cin >> x;

    segment_tree segtree(n, a);

    while (m--) {
        int pos, val;
        cin >> pos >> val, pos--;
        segtree.update(1, 0, n - 1, pos, val);
        cout << segtree.maxi[1].sub << endl;
    }
}

/*
USE LONG LONG!!!!
*/