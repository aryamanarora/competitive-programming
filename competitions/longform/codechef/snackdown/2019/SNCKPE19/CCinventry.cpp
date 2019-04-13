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
    string s;
    cin >> n >> s;
    vi sum(n);
    ll start = -1, boxstart = -1, ct = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '#' and start == -1) {
            start = i;
        }
        if (start != -1 and boxstart == -1 and s[i] == '#') boxstart = i;
        if (boxstart != -1 and s[i] == '#') {
            sum[i] = 1 + sum[i - 1];
        }
    }
    if (boxstart == -1) {
        cout << 0 << endl;
        return;
    }
    ll ans = 0, pos = start - 1;
    for (int i = start; i < n; i++) {
        if (s[i] == '#') {
            pos = max(pos + 2, (ll) i);
            if (pos >= n - 1) {
                cout << -1 << endl;
                return;
            }
            ans += (pos - i);
            ans += (pos - (start + ct));
            ct++;
        }
    }
    cout << ans << endl;
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