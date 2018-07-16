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

int main() {
    ll n = 0LL;
    cin >> n;
    map<ll, ll> a;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[x]++;
    }
    int ans = 0;
    while (!a.empty()) {

    }
}