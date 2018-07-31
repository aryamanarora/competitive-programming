#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;

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

    ll n, m;
    cin >> n >> m;

    vi diffs;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        diffs.pb(a-b);
        sum += a;
    }
    sort(diffs.rbegin(), diffs.rend());

    int ans = 0;
    for (int i = 0; i < n and sum > m; i++) {
        sum -= diffs[i];
        ans++;
    }

    if (sum <= m) cout << ans << endl;
    else cout << "-1" << endl;
}