#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
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
    int n, m;
    vi b;
    vector<pair<int, bool>> g;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        g.push_back(mp(x, false));
    }

    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    int ans = 0;
    for (auto x : b) {
        for (int i = 0; i < m; i++) {
            if (!g[i].s and abs(x - g[i].f) <= 1) {
                ans++;
                g[i].s = true;
                break;
            }
        }
    }
    cout << ans << "\n";
}