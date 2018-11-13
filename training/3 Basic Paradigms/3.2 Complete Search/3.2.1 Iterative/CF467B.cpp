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

    int n, m, k;
    cin >> n >> m >> k;
    vi friends(m);
    for (int i = 0; i < m; i++) cin >> friends[i];
    int fedor, diff, ans = 0;
    cin >> fedor;
    for (int i = 0; i < m; i++) {
        diff = 0;
        for (int j = 0; j < n; j++) {
            if ((1 << j & fedor) != (1 << j & friends[i])) diff++;
        }
        if (diff <= k) ans++;
    }
    cout << ans << endl;
}