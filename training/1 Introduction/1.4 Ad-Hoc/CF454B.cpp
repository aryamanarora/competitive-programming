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
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    int a, olda;
    cin >> olda;
    int first = olda, last;
    int rift = n, ct = 0;
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a < olda) {
            rift = i;
            ct++;
        }
        olda = a;
    }
    last = a;
    
    if (ct > 1) cout << -1 << endl;
    else if (ct == 1 and last > first) cout << -1 << endl;
    else cout << n - rift << endl;
}