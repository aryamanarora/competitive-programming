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

    ll n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << (n * (n + 1)) / 2 << endl;
        return 0;
    }
    vector<vi> a(m, vi(n));
    map<int, int> key;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i == 0) key[a[i][j]] = j;
            a[i][j] = key[a[i][j]];
        }
    }

    vector<vi> ans(m, vi(n));
    for (int i = 0; i < n; i++) {
        ans[0][i] = n - i;
    }
    for (int i = 1; i < m; i++) {
        int start = 0, end = 0;
        while (true) {
            ans[i][a[i][start]] = max(ans[i][a[i][start]], end - start + 1);
            if (end == n - 1 and start == n - 1) break;
            if (a[i][end + 1] - a[i][start] != end - start + 1) {
                if (start == end) start = ++end;
                else start++;
            }
            else end++;
        }
    }

    ll anss = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[0][i] = min(ans[0][i], ans[j][i]);
        }
        anss += ans[0][i];
    }
    cout << anss << endl;
}