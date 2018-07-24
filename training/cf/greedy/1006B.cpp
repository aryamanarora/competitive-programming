#include <vector>
#include <complex>
#include <iostream>
#include <algorithm>

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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb(mp(x, i));
    }
    sort(a.rbegin(), a.rend());
    int profit = 0;
    vi ans;
    ans.pb(n+1);
    for (int i = 0; i < k; i++) {
        profit += a[i].f;
        ans.pb(a[i].s + 1);
    }
    cout << profit << "\n";
    sort(ans.begin(), ans.end());
    if (k == 1) {
        cout << n << "\n";
        return 0;
    }
    else if (k == 2) {
        int k = (ans[0] + ans[1])/2;
        cout << k << " " << n - k << "\n";
        return 0;
    }
    if (ans[0] > 1) {
        ans.pb(0);
        sort(ans.begin(), ans.end());
        for (int i = 1; i < k; i++) {
            cout << ans[i] - ans[i - 1] << " ";
        }
        if (ans[k] < n) cout << n - ans[k - 1] << " ";
        else cout << ans[k] - ans[k - 1] << " ";
    }
    else {
        ans.pb(n + 1);
        sort(ans.begin(), ans.end());
        for (int i = 0; i < k; i++) {
            cout << ans[i + 1] - ans[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}