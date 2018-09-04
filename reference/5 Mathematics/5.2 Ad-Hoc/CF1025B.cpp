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

const ll MAX = 2000000001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;
    ll x, y;
    vl a(n), b(n);
    set<ll> left, right, oldleft, oldright;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    ll g = lcm(a[0], b[0]);
    for (int i = 1; i < n; i++) {
        g = gcd(g, lcm(a[i], b[i]));
    }
    if (g == 1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
		if (gcd(g, a[i]) > 1) g = gcd(g, a[i]);
		else g = gcd(g, b[i]);
	}
    cout << g << endl;
}