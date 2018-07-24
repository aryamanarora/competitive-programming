#include <vector>
#include <complex>
#include <iostream>
#include <algorithm>
#include <set>

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
    ll n = 0;
    cin >> n;
    vl a(n), sum(n), sum_rev(n);
    vl x, y;
    ll sum_n = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_n += a[i];
        sum[i] = sum_n;
    }

    ll ans = 0;
    if (sum_n % 3 != 0) {
        cout << ans << "\n";
        return 0;
    }

    for (ll i = 0; i < n; i++) {
        if (sum[i] == sum_n/3) x.pb(i);
        if (sum[i] == 2 * (sum_n/3) and i != n - 1) y.pb(i+1);
    }

    int size = y.size(), min_b = 0;

    for (auto a : x) {
        for (int b = min_b; b < size; b++) {
            if (y[b] >= a + 2) {
                min_b = b;
                ans += size - b;
                break;
            }
        }
    }

    cout << ans << "\n";
}