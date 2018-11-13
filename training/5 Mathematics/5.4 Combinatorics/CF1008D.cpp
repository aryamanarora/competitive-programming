#include <iostream>
#include <vector>
#include <complex>
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
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        set<ll> divisors;
        ll max = 0;
        ll r = 6;
        if (a > max) max = a;
        if (b > max) max = b;
        if (c > max) max = c;
        if (a == max and b == max and c == max) r = 3;
        else if ((a == max and b == max) or (b == max and c == max) or (a == max and c == max)) r = 2;
        else r = 1;

        for (ll i = 1LL; i <= max/2LL + 1LL; i++) {
            if (a % i == 0 or b % i == 0 or c % i == 0) divisors.insert(i);
        }
        divisors.insert(a);
        divisors.insert(b);
        divisors.insert(c);

        ll n = divisors.size();
        ll ans = 1;

        // number of repeating combinations: (n + r - 1)!/(r! * (n-1)!)
        for (ll j = n; j < n + r; j++) {
            ans *= j;
        }
        ans /= r;
        if (r == 3) ans /= 2;
        cout << n << " " << ans << "\n";
    }
    return 0;
}