#include <bits/stdc++.h>

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
    ll n = 0, x;
    cin >> n >> x;
    vi c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());
    ll ans = 0;
    for (auto s : c) {
        ans += s * x;
        x = max(x-1LL, 1LL); 
    }
    cout << ans << "\n";
}