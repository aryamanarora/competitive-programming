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
    ll n = 0;
    cin >> n;
    vi arr(n);
    map<ll, pair<ll, ll>> q;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        q[arr[i]] = mp(i + 1, n - i);
    }
    ll m = 0;
    cin >> m;
    ll vasya = 0, petya = 0;
    for (ll i = 0; i < m; i++) {
        ll x;
        cin >> x;
        vasya += q[x].f;
        petya += q[x].s;
    }
    cout << vasya << " " << petya << "\n";
}