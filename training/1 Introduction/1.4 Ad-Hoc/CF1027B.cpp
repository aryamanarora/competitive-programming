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

    ll n, q;
    cin >> n >> q;
    ll x, y;
    if (n % 2) {
        while (q--) {
            cin >> x >> y;
            x--; y--;
            ll pos = x * n + y;
            if (pos % 2 == 0) cout << pos / 2 + 1 << endl;
            else cout << (n * n) / 2 + (pos - 1) / 2 + 2 << endl;
        }
    }
    else {
        while (q--) {
            cin >> x >> y;
            x--; y--;
            ll pos = x * n + y;
            if ((x + y) % 2 == 0) cout << pos / 2 + 1 << endl;
            else cout << (n * n) / 2 + (pos - 1) / 2 + 1 + (x % 2) << endl;
        }
    }
}