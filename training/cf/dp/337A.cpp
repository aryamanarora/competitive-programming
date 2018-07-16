#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

int main() {
    int n, m = 0;
    cin >> n >> m;
    vi f(m);
    for (int i = 0; i < m; i++) cin >> f[i];
    sort(f.begin(), f.end());
    int ans = 10e9;
    for (int i = 0; i <= m - n; i++) {
        ans = min(ans, f[i + n - 1] - f[i]);
    }
    cout << ans << "\n";
}