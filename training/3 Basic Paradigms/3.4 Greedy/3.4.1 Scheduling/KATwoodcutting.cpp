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

void solve() {
    int n;
    cin >> n;
    vl a(n);
    int b, c;
    for (int i = 0; i < n; i++) {
        cin >> b;
        while (b--) {
            cin >> c;
            a[i] += c;
        }
    }
    sort(a.begin(), a.end());
    ll ans = 0, sum = 0;
    for (auto x : a) {
        sum += x;
        ans += sum;
    }
    cout << fixed << setprecision(10) << static_cast<ld>(ans) / n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) solve();
}