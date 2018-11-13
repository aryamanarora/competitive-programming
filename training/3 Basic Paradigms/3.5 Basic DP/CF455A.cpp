#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

map<ll, ll> a;
map<ll, ll> dp;

int main() {
    ll n = 0LL;
    cin >> n;
    ll max_n = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[x]++;
        max_n = max(max_n, x);
    }
    dp[0LL] = 0LL;
    dp[1LL] = a[1LL];

    for (ll i = 2LL; i <= max_n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + a[i] * i);
    }

    cout << dp[max_n] << endl;
}