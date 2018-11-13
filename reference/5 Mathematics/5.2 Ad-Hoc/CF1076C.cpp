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

void solve() {
    double d;
    cin >> d;
    double x = (d + sqrt(d * d - 4 * d)) / 2.0;
    if (isnan(x)) {
        cout << "N" << endl;
        return;
    }
    cout << "Y " << setprecision(9) << fixed << x << " " << static_cast<double>(d) - x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}

/*
x^2 + c = cx
x^2 - cx + c = 0
x = (c + sqrt(c ^ 2 - 4 * c)) / 2
*/