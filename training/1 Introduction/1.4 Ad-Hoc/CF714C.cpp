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

ll get_pattern(ll x) {
    ll ans = 0;
    int pos = 0;
    while (x > 0) {
        ans += (((x % 10) % 2) * pow(10LL, pos));
        x /= 10;
        pos++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<ll, int> a;
    ll t, x;
    char q;
    cin >> t;
    while (t--) {
        cin >> q >> x;
        if (q == '+') a[get_pattern(x)]++;
        else if (q == '-') a[get_pattern(x)]--;
        else {
            cout << a[x] << endl;
        }
    }
}