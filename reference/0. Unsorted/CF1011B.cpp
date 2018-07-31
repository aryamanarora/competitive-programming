#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <list>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    int n, m = 0;
    cin >> n >> m;
    map<int, int> a;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    vi vals;
    for (auto x : a) {
        vals.pb(x.s);
    }
    sort(vals.rbegin(), vals.rend());
    int ans = 0;
    for (int i = 1; i <= m / n; i++) {
        int packages = i * n; // needed packages
        for (auto x : vals) {
            if (x < i) break;
            while (x - i >= 0) {
                x -= i;
                packages -= i;
            }
        }
        if (packages <= 0) ans = max(i, ans);
    }
    cout << ans << endl;
}

/*
3 9
9
1: 3
2: 
*/