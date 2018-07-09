#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
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
    vi hash = {1};
    ll val = 1;
    for (ll i = 0; i <= 32; i++) {
        val *= 2;
        hash.pb(val);
    }
    ll n = 0;
    cin >> n;
    vi a(n);
    map<ll, ll> e;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        e[a[i]]++;
    }
    ll ans = n;
    for (ll i = 0; i < n; i++) {
        bool okay = false;
        for (auto x : hash) {
            if (x - a[i] != a[i]) {
                if (e[x - a[i]] > 0) {
                    okay = true;
                }
            }
            else if (a[i] == x - a[i] and e[x-a[i]] > 1) okay = true;
        }
        if (okay) ans--;
    }
    cout << ans << "\n";
}