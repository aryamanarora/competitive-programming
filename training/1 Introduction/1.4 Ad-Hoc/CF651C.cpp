#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n;
    map<ii, ll> all;
    map<int, ll> a, b;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        all[{x, y}]++;
        a[x]++;
        b[y]++;
    }

    ll ans = 0;
    for (auto [_, c] : a) {
        ans += ((c * (c - 1)) / 2);
    }
    for (auto [_, c] : b) {
        ans += ((c * (c - 1)) / 2);
    }
    for (auto [_, c] : all) {
        ans -= ((c * (c - 1)) / 2);
    }

    cout << ans << endl;
}