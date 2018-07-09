#include <map>
#include <vector>
#include <iostream>
#include <cmath>
#include <complex>

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
    int n = 0, a;
    cin >> n >> a;
    a--;
    vi t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    map<int, int> criminals;
    for (int i = 0; i < n; i++) {
        criminals[abs(a-i)] += t[i];
    }
    int min_dist = min(a, n - a - 1), ans = 0;
    for (auto x : criminals) {
        if (x.f == 0) ans += x.s;
        else if (x.f <= min_dist) {
            if (x.s != 1) ans += x.s;
        }
        else ans += x.s;
    }
    cout << ans << "\n";
}