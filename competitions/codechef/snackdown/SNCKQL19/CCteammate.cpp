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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, a;
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> ct;
        for (int i = 0; i < n; i++) {
            cin >> a;
            ct[a]++;
        }
        ll ans = 1;
        for (auto &x : ct) {
            for (int i = 3; i < x.s; i += 2) {
                ans *= (i % MOD);
                ans %= MOD;
            }
        }
    }
}