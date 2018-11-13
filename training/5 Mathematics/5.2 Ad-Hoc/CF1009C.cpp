#include <iostream>
#include <iomanip>
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
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ll n, m;
    cin >> n >> m;
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        ll x, d;
        cin >> x >> d;
        sum += x * n;
        if (d >= 0) {
            sum += (n * (d * (n - 1LL))) / 2LL;
        }
        else {
            sum += (n / 2LL + 1LL) * ((d * (n / 2LL)));
            if (n % 2LL == 0LL) {
                sum -= d * (n / 2LL);
            }
        }
    }
    cout << static_cast<double>(sum) / static_cast<double>(n) << "\n";
}