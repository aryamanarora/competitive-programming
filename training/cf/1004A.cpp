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
    ll n, d;
    cin >> n >> d;
    vl x;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        x.pb(a);
    }
    sort(x.begin(), x.end());
    set<ll> ans = {x[0] - d, x[n - 1] + d};
    if (n == 2) {
        if (x[1] - x[0] > d*2) {
            ans.insert(x[1] - d);
            ans.insert(x[0] + d);
        }
        else if (x[1] - x[0] == d*2) {
            ans.insert(x[1] - d);
        }
    }
    else if (n > 2) {
        for (int i = 0; i < n; i++) {
            if (i > 0 and abs((x[i] - d) - x[i-1]) >= d) {
                ans.insert(x[i] - d);
            }
            if (i < n-1 and abs((x[i] + d) - x[i+1]) >= d) {
                ans.insert(x[i] + d);
            }
        }
    }
    cout << ans.size() << "\n";
}