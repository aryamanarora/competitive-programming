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

template<typename T>
T least_significant_one(T x) {
    return (x & (-x));
}

struct fenwick_tree {
    int n;
    vi freq;
    fenwick_tree(int N) : n(N), freq(N + 1, 0) {};
    int sum(int a) {
        int res = 0;
        for (; a; a -= least_significant_one(a)) res += freq[a];
        return res;
    }
    void add(int a) {
        for (; a <= n; a += least_significant_one(a)) freq[a]++;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("bphoto.in");
    ofstream fout("bphoto.out");

    int n;
    fin >> n;

    // store values in original and sorted order
    vi a(n), sorted(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
        sorted[i] = a[i];
    }

    // sort the values
    sort(sorted.rbegin(), sorted.rend());
    
    // value compression for Fenwick
    map<int, int> val;
    for (int i = 0; i < n; i++) {
        val[sorted[i]] = i + 1;
    }

    // make the tree from the left
    vi l(n);
    fenwick_tree left(n);
    for (int i = 0; i < n; i++) {
        // dynamic update
        left.add(val[a[i]]);
        // get the value
        l[i] = left.sum(val[a[i]] - 1);
    }

    // now the right
    vi r(n);
    fenwick_tree right(n);
    for (int i = n - 1; i >= 0; i--) {
        right.add(val[a[i]]);
        r[i] = right.sum(val[a[i]] - 1);
    }

    // finally get the answer
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] * 2 < r[i] or r[i] * 2 < l[i]) ans++;
    }
    fout << ans << endl;
}

/*
USE LONG LONG!!!!
*/