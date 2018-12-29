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
    
    int n = -1;
    while (cin >> n and n != 0) {
        // shoelace formula
        vii a(n);
        for (int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;
        a.pb(a[0]);
        ll area = 0;
        for (int i = 0; i < n; i++) {
            area += a[i].f * a[i + 1].s;
            area -= a[i].s * a[i + 1].f;
        }

        if (area < 0) cout << "CW ";
        else cout << "CCW ";
        cout << abs(area) / 2 << (area % 2 ? ".5" : ".0") << endl;
    } 
}