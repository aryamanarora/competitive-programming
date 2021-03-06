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
    string a, b;
    map<ii, i> c;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        c[mp(a[i], b[i])]++;
    }
    int ans = c[mp(0, 1)] * c[mp(1, 0)];
    ans += c[mp(0, 0)] * c[mp(1, 1)];
    ans += c[mp(0, 0)] * c[mp(1, 0)];
    cout << ans << endl;
}