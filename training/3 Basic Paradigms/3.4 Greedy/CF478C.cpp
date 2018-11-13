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

    vl b(3);
    cin >> b[0] >> b[1] >> b[2];
    sort(b.begin(), b.end());
    if (2 * (b[0] + b[1]) <= b[2]) cout << b[0] + b[1] << endl;
    else cout << (b[0] + b[1] + b[2]) / 3 << endl;
}