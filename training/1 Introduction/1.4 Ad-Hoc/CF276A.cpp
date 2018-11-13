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

    ll n, k;
    cin >> n >> k;
    ll f, t;
    ll max_joy = 0;
    for (int i = 0; i < n; i++) {
        cin >> f >> t;
        ll joy = f;
        if (t > k) joy -= (t - k);
        if (i == 0) max_joy = joy;
        else max_joy = max(joy, max_joy);
    }
    cout << max_joy << endl;
}