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
    vi arr;

    segment_tree(int N, vi &s) : n(4 * N), arr(4 * N) {
        build(s, 1, 0, N - 1);
    };

    void build(vi &a, int v, int tl, int tr) {
        if (tl == tr) {
            arr[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);

            if (static_cast<int>(log2(tr - tl + 1)) % 2) {
                arr[v] = arr[v * 2] | arr[v * 2 + 1];
                // cout << arr[v * 2] << " | " << arr[v * 2 + 1] << " = " << arr[v] << endl;
            }
            else {
                arr[v] = arr[v * 2] ^ arr[v * 2 + 1];
                // cout << arr[v * 2] << " ^ " << arr[v * 2 + 1] << " = " << arr[v] << endl;
            }
        }
    }

    int value() {
        return arr[1];
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            arr[v] = new_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v * 2, tl, tm, pos, new_val);
            else update(v * 2 + 1, tm + 1, tr, pos, new_val);
            
            if (static_cast<int>(log2(tr - tl + 1)) % 2)
                arr[v] = arr[v * 2] | arr[v * 2 + 1];
            else arr[v] = arr[v * 2] ^ arr[v * 2 + 1];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    n = pow(2, n);
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    segment_tree segtree(n, a);
    
    int pos, new_value;
    while (m--) {
        cin >> pos >> new_value;
        pos--;
        segtree.update(1, 0, n - 1, pos, new_value);
        cout << segtree.value() << endl;
    }
}