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
    int n;
    cin >> n;
    bool allneg = true;
    vi a(n);
    map<int, vi> key;

    int cycle = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != -1) {
            if (i > 0 and a[i-1] != -1 and ((a[i] - a[i-1] > 1) or (a[i-1] > a[i] and a[i] != 1))) {
                cout << "impossible" << endl;
                return;
            }
            if (i > 0 and a[i-1] != -1 and a[i] == 1) {
                if (cycle == -1) cycle = a[i-1];
                else {
                    cout << "impossible" << endl;
                    return;
                }
            }
            allneg = false;
            for (int j = 1; a[i] - j > 0 and i - j >= 0; j++) {
                if (a[i - j] == -1) a[i - j] = a[i] - j;
                else if (a[i - j] != a[i] - j) {
                    cout << "impossible" << endl;
                    return;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != -1) key[a[i]].pb(i);
    }
    if (allneg or key[1].size() <= 1) {
        cout << "inf" << endl;
        return;
    }

    int ans = -1;
    int maxi;
    for (auto gap : key) {
        maxi = gap.f;
        for (int i = 1; i < gap.s.size(); i++) {
            if (ans == -1) ans = gap.s[i] - gap.s[i-1];
            else ans = gcd(ans, gap.s[i] - gap.s[i-1]);
        }
    }
    if (ans < maxi) cout << "impossible" << endl;
    else cout << ans << endl;
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