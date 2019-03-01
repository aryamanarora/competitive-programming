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
    vl a(n);
    ll sum_n = 0;
    for (auto &x : a) cin >> x, sum_n += x;

    ll ans = 0;
    if (sum_n % 3 != 0) {
        cout << ans << endl;
        return 0;
    }

    ll sum = 0;
    ll one = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i];
        if (sum == (sum_n / 3) * 2) ans += one;
        if (sum == sum_n / 3) one++;
    }

    cout << ans << endl;
}