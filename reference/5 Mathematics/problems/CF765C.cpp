#include <vector>
#include <complex>
#include <iostream>
#include <algorithm>

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
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans = -1;
    if ((a % k == 0 and a != 0) or (b % k == 0 and b != 0) or (a > k and b > k)) {
        ans = (a / k + b / k);
    }
    if (ans == 0) ans = -1;
    cout << ans  << "\n";
}