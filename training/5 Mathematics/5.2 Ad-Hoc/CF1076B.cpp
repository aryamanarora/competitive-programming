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

    ll n;
    cin >> n;
    bool divided = false;
    if (n % 2 == 0) {
        cout << n / 2 << endl;
        return 0;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            n -= i;
            divided = true;
            break;
        }
    }
    if (!divided) { 
        cout << 1 << endl;
        return 0;
    }
    cout << 1 + (n / 2LL) << endl;
}