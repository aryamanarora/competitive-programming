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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<int, bool> a;

    for (int i = 1; i <= m; i++) a[i] = false;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = x; j <= y; j++) a[j] = true;
    }

    vi ans;
    for (auto x : a) if (x.s == false) ans.pb(x.f);

    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}