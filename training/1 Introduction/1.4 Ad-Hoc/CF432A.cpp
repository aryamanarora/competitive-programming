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

    int n, k, a;
    cin >> n >> k;
    k = 5 - k;

    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }

    vi m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        m.pb(a);
    }
    sort(m.begin(), m.end());

    int pos = 2, ans = 0;
    while (m[pos] <= k) {
        ans++;
        pos += 3;
        if (pos >= n) break;
    }
    cout << ans << endl;
}