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

    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    int diff = abs(x - y);
    int elevator = c * 3 + abs(z - x) * b + diff * b;
    int stairs = a * diff;
    cout << elevator << " " << stairs << ": " << (elevator <= stairs ? "YES" : "NO") << endl;
}