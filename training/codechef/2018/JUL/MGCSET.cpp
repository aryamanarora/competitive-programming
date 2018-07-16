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
    int T;
    cin >> T;
    vl anss;
    for (int ctr = 0; ctr < T; ctr++) {
        ll n = 0, m;
        cin >> n >> m;
        vl a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll div = 0LL;
        for (int i = 0; i < n; i++) {
            if (a[i] % m == 0) div++;
        }
        anss.pb(pow(2, div) - 1);
    }
    for (auto x : anss) cout << x << "\n";
}