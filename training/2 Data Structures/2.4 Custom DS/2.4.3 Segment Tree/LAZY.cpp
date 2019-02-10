struct segment_tree {
    int n;
    vi sum, maxi, mini;

    segment_tree(int N, vi &s) : n(N), sum(4 * N), maxi(4 * N), mini(4 * N) {
        build(s, 1, 0, N - 1);
    };

    void build(vi &a, int v, int tl, int tr) {
        if (tl == tr) maxi[v] = mini[v] = sum[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);

            maxi[v] = max(maxi[v * 2], maxi[v * 2 + 1]);
            mini[v] = min(mini[v * 2], mini[v * 2 + 1]);
            sum[v] = 0;
        }
    };

    void update(int v, int tl, int tr, int l, int r, int add) {
        if (l > r) return;
        if (l == tl and r == tr) {
            sum[v] += add;
            maxi[v] += add;
            mini[v] += add;
        }
        else {
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), add);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);

            maxi[v] = max(maxi[v * 2], maxi[v * 2 + 1]);
            mini[v] = min(mini[v * 2], mini[v * 2 + 1]);
        }
    }

    void update(int l, int r, int add) {
        update(1, 0, n - 1, l, r, add);
    };

    int get_min(int v, int tl, int tr, int l, int r) {
        if (l > r) return INT_MAX;
        if (sum[v] != 0) {
            mini[v] += sum[v];
            if (l != r) {
                sum[v * 2] += sum[v];
                sum[v * 2 + 1] += sum[v];
            }
            sum[v] = 0;
        }
        if (l == tl and r == tr) return mini[v];
        int tm = (tl + tr) / 2;
        return min(
            get_min(v * 2, tl, tm, l, min(r, tm)),
            get_min(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }

    int get_max(int v, int tl, int tr, int l, int r) {
        if (l > r) return INT_MIN;
        if (sum[v] != 0) {
            maxi[v] += sum[v];
            if (l != r) {
                sum[v * 2] += sum[v];
                sum[v * 2 + 1] += sum[v];
            }
            sum[v] = 0;
        }
        if (l == tl and r == tr) return mini[v];
        int tm = (tl + tr) / 2;
        return max(
            get_max(v * 2, tl, tm, l, min(r, tm)),
            get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }
};