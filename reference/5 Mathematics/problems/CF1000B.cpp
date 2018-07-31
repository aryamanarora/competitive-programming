#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
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
    ll n, M;
    cin >> n >> M;
    ll ans = 0, max_gap = 0;
    if (n % 2 == 1) {
        ll x;
        cin >> x;
        ans = x;
        max_gap = x;
        for (int i = 0; i < n - 1; i++) {
            ll y;
            cin >> y;
            if (i % 2 == 1) ans += y - x;
            max_gap = max(max_gap, y - x);
            x = y;
        }
        max_gap = max(max_gap, M - x);
        cout << max(ans, (M - ans) + (max_gap - 1)) << "\n";
    }
    else {
        ll x;
        cin >> x;
        ans = x;
        for (int i = 0; i < n - 1; i++) {
            ll y;
            cin >> x;
            if (i % 2 == 1) ans += y - x;
            max_gap = max(max_gap, y - x);
        }
    }
}

// 0----4  6-7   10
// 0---3 4--6 7---10


// 0-----5 6-7 8-9 10-11