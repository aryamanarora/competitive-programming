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
    vi left, right, all;

    segment_tree(int N, string &s) : n(4 * N), left(4 * N), right(4 * N), all(4 * N) {
        build(s, 1, 0, N - 1);
    };

    void build(string &a, int v, int tl, int tr) {
        if (tl == tr) {
            if (a[tl] == '(') left[v] = 1;
            else right[v] = 1;
            all[v] = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);

            int matched = min(left[v * 2], right[v * 2 + 1]);

            left[v] = left[v * 2] + left[v * 2 + 1] - matched;
            right[v] = right[v * 2] + right[v * 2 + 1] - matched;
            all[v] = all[v * 2] + all[v * 2 + 1] + matched;
        }
    }

    tuple<int, int, int> sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return {0, 0, 0};
        if (l == tl and r == tr) {
            return {left[v], right[v], all[v]};
        }

        int tm = (tl + tr) / 2;

        tuple<int, int, int> lefts = sum(v * 2, tl, tm, l, min(r, tm)),
                             rights = sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

        int matches = min(get<0>(lefts), get<1>(rights));
        return {
            get<0>(lefts) + get<0>(rights) - matches,
            get<1>(lefts) + get<1>(rights) - matches,
            get<2>(lefts) + get<2>(rights) + matches,
        };
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int len = s.length();
    segment_tree a(len, s);
    
    int q, ans, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        l--; r--;
        ans = get<2>(a.sum(1, 0, len - 1, l, r));
        cout << ans * 2 << endl;
    }
}