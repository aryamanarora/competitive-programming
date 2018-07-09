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
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    ll a_len = a.length(), b_len = b.length();
    ll ans = a_len + b_len;

    for (ll i = 0LL; i < min(a_len, b_len); i++) {
        if (a[i] == b[i]) {
            ans -= 2;
        }
        else break;
    }
    cout << ans << "\n";
}