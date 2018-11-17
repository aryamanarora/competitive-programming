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

    int n;
    cin >> n;
    vi a(n);
    map<ll, int> b;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        b[a[i]]++;
    }

    vi ans;
    for (int i = 0; i < n; i++) {
        ll c = sum - a[i];
        if (c % 2) continue;
        c /= 2;
        if (a[i] == c) {
            if (b[c] > 1) ans.pb(i + 1);
        }
        else if (b[c] > 0) ans.pb(i + 1);
    }

    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}