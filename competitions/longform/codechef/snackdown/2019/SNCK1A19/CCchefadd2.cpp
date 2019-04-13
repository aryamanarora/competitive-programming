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

ll choose(ll n, ll k) {
    if (k == 0) return 1;
    return (n * choose(n - 1, k - 1)) / k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    ll a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << bitset<16>(a) << " " << bitset<16>(b) << endl;
        ll olda = a, oldb = b;
        a = __builtin_popcount(a); b = __builtin_popcount(b);
        int ans = 0;
        for (int i = 0; i < c; i++) {
            if (__builtin_popcount(i) == a and __builtin_popcount(c - i) == b) {
                for (int j = 0; j < 16; j++) {
                    cout << (((1 << j) & i) ? 1 : 0) + (((1 << j) & (c - i)) ? 1 : 0);
                }
                cout << endl;
                ans++;
            }
        }
        cout << ans << endl;
    }
}