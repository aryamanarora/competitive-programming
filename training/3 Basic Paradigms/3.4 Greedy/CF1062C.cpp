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

const ll MOD = 1000000007;
const int MAX = 100001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi two(MAX);
    two[0] = 1;
    for (int i = 1; i < MAX; i++) {
        two[i] = two[i - 1] * 2;
        two[i] %= MOD;
    }

    int n, q; char z;
    cin >> n >> q;
    vi a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> z;
        if (z == '1') a[i]++;
        if (i > 0) a[i] += a[i - 1];
    }
    
    int l, r;
    while (q--) {
        cin >> l >> r;
        l--; r--;
        int ct = (l == 0 ? a[r] : a[r] - a[l - 1]);
        ll ans = (two[ct] - 1LL + MOD) % MOD;
        ans *= two[((r - (l - 1)) - ct)] % MOD;
        ans %= MOD;
        cout << ans << endl;
    }
}