#include <iostream>
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
    ll v, e;
    cin >> v >> e;
    vector<pair<ll, ll>> ans;
    for (ll i = 1LL; i <= v and ans.size() <= e; i++) {
        for (ll j = i; j <= v and ans.size() <= e; j++) {
            if (__gcd(i, j) == 1) ans.pb(mp(i, j));
        }
    }
    if (ans.size() < e) {
        cout << "Impossible\n";
    }
    else {
        cout << "Possible\n";
        for (auto x : ans) cout << x.f << " " << x.s << "\n";
    }
}