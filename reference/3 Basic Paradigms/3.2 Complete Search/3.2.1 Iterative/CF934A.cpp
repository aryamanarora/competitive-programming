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

const ll INF = 1000000001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, m = 0;
    cin >> n >> m;
    vl a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    ll rm, prod = -INF * INF;
    for (auto &x : a) {
        for (auto &y : b) {
            if (x * y >= prod) {
                rm = x;
                prod = x * y;
            }
        }
    }

    ll ans = -INF * INF;
    bool rmfound = false;
    for (auto &x : a) {
        if (x == rm and !rmfound) {
            rmfound = true;
            continue;
        }
        for (auto &y : b) {
            ans = max(x * y, ans);
        }
    }

    cout << ans << endl;
}