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
    int n = 0, m;
    cin >> m >> n;

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p.pb(mp(b, a));
    }
    sort(p.rbegin(), p.rend());

    int ans = 0;
    for (int i = 0; i < n and m > 0; i++) {
        if (p[i].s >= m) {
            ans += m * p[i].f;
            m = 0;
        }
        else {
            ans += p[i].s * p[i].f;
            m -= p[i].s;
        }
    }
    cout << ans << "\n";
}