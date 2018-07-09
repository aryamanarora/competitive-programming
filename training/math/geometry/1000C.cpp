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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> x;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        x.pb(mp(a, 1));
        x.pb(mp(a, -1));
    }
    sort(x.begin(), x.end());
    ll ans[n];
    for (int i = 0; i < n; i++) ans[i] = 0;
    ll points = 0;
    for (int i = 0; i < n-1; i++) {
        points += x[i].s;
    }
}