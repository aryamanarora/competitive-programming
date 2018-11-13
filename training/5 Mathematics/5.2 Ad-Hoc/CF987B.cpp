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

    long double x, y;
    cin >> x >> y;
    if (abs(log(x) / x - log(y) / y) < 1e-8) {
        cout << "=" << endl;
        return 0;
    }
    if (log(x) / x > log(y) / y) cout << ">" << endl;
    else cout << "<" << endl;
}