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
    int n, m, x;
    cin >> n >> m;
    vi a, b;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != 0) a.pb(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x != 0) b.pb(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << (a != b ? "Alice" : "Bob") << endl;
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