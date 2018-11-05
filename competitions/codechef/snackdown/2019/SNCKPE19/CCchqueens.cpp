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

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    ll ans = 0;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (a == x and b == y) continue;
            ans += ((n * m) - 2);
            if (a == x) {
                if (b < y) ans -= (b + (y - b - 2));
                else ans -= ((m - b - 1) + (b - y - 2));
            }
            if (b == y) {
                if (a < x) ans -= (a + (x - a - 2));
                else ans -= ((n - a - 1) + (a - x - 2));
            }
        }
    }
    cout << ans * 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}