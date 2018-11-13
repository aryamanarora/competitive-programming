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

    int n, m;
    bool one = true;
    cin >> n >> m;
    if (n > m + 1 or m > (n + 1) * 2) {
        cout << -1 << endl;
        return 0;
    }
    if (m > n) {
        for (int i = 0; m > n; i++) {
            if (i % 2) {
                cout << 11;
                n -= 2;
            }
            else {
                cout << 0;
                m -= 1;
            }
        }
    }
    cout << endl;
}