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

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
}

ld bs(ld x1, ld y1, ld x2, ld y2, ld x3) {
    ld lo = y1, hi = y2;
    ld mid;
    while (hi - lo >= 1e-10) {
        mid = (lo + hi) / 2.0;
        if (dist(x1, y1, x3, (mid + lo) / 2) + dist(x3, (mid + lo) / 2, x2, y2) < dist(x1, y1, x3, (mid + hi) / 2) + dist(x3, (mid + hi) / 2, x2, y2)) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return dist(x1, y1, x3, mid) + dist(x3, mid, x2, y2);
}

void solve() {
    ld a, b, c, x;
    cin >> a >> b >> c >> x;
    cout << bs(0.0, 0.0, b, a, b + c) << endl;
    x /= 100.0;

    ld ans = 0.0;
    ans += bs(0.0, 0.0, b, a, b + c);
    ans += dist(0.0, 0.0, b * x, a * x);
    ans += bs(b * x, a * x, b, a, b + c);
    cout << fixed << setprecision(9) << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}

/*
USE LONG LONG!!!!

bcmnvxz
*/