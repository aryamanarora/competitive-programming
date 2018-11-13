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

    ll x, y;
    cin >> x >> y;
    ll a = abs(x) + abs(y);
    if (x > 0 and y > 0) cout << "0 " << a << a << " 0" << endl;
    else if (x > 0 and y < 0) cout << "0 " << -a << a << " 0" << endl;
    else if (x < 0 and y > 0) cout << -a << " 0 0 " << a << endl;
    else cout << -a << " 0 0 " << -a << endl;
}