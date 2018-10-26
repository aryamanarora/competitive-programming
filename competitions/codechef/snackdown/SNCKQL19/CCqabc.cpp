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

void inc(vi &a, int pos, int n) {
    a[pos] += n;
    a[pos + 1] += (2 * n);
    a[pos + 2] += (3 * n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vi a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        bool okay = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i] and i < n - 2) inc(a, i, b[i] - a[i]);
            else if (a[i] != b[i]) {
                okay = false;
                break;
            }
        }
        cout << (okay ? "TAK" : "NIE") << endl;
    }
}