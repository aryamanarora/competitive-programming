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

    int t;
    cin >> t;
    ll a, b, c;
    while (t--) {
        cin >> a >> b >> c;
        b = -b;
        ll ans = a * (c / 2) + b * (c / 2);
        if (c % 2 == 1) ans += a;
        cout << ans << endl;
    }
}