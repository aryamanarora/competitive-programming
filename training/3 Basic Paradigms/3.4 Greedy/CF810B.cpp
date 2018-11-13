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
    ll n, f;
    cin >> n >> f;
    vector<pair<ll, ll>> arr;
    ll ans = 0LL;
    for (ll i = 0LL; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        arr.pb(mp(min(a * 2LL, b) - min(a, b), min(a, b)));
        ans += min(a, b);
    }
    sort(arr.rbegin(), arr.rend());
    for (ll i = 0; i < f; i++) ans += arr[i].f;
    cout << ans << "\n";
}