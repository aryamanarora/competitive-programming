#include <algorithm>
#include <vector>
#include <iostream>
#include <array>
#include <queue>
#include <functional>

typedef long long ll;
typedef long double ld;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;

    vector<array<ll, 3>> kn;

    for (ll i = 0; i < n; i++) {
        array<ll, 3> x;
        x[0] = i;
        cin >> x[1];
        kn.push_back(x);
    }
    for (ll i = 0; i < n; i++) {
        cin >> kn[i][2];
    }

    sort(kn.begin(), kn.end(), [](const array<ll, 3>& a, const array<ll, 3>& b)
    {
        return a[1] < b[1];
    });
    ll ans[n];
    priority_queue<ll , vector<long long >, greater<long long > > q;
    ll max_coins = 0;
    for (int i = 0; i < n; i++) {
        ll id = kn[i][0];
        ans[id] = max_coins += kn[i][2];
        q.push(kn[i][2]);
        if (q.size() > k) {
            max_coins -= q.top();
            q.pop();
        }
    }

    for (ll i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}