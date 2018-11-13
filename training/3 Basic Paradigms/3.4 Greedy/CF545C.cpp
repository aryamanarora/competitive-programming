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

    int n;
    cin >> n;
    vii a(n);
    for (int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;

    int ans = 1;
    bool right = false;
    for (int i = 1; i < n; i++) {
        if (i == n - 1) ans++;
        else if (a[i].f - a[i].s > a[i-1].f + a[i-1].s) {
            ans++;
            right = false;
        }
        else if (!right and a[i].f - a[i].s > a[i-1].f) {
            ans++;
        }
        else if (a[i].f + a[i].s < a[i+1].f) {
            ans++;
            right = true;
        }
        else right = false;
    }

    cout << ans << endl;
}