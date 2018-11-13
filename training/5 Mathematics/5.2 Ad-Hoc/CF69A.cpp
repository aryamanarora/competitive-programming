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
    int x = 0, y = 0, z = 0;
    int a, b, c;
    while (n--) {
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }
    cout << (x == 0 and y == 0 and z == 0 ? "YES" : "NO") << endl;
}