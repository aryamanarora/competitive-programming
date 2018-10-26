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
    vi l(n), r(n);
    int ct = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] > i) {
            cout << "NO" << endl;
            return 0;
        }
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        if (r[i] > n - i - 1) {
            cout << "NO" << endl;
            return 0;
        }
        ct = max(ct, l[i] + r[i]);
    }
    if (ct >= n) {
        cout << "NO" << endl;
        return 0;
    }
    ct++;
    vi ans(n);
    for (int i = 0; i < n; i++) ans[i] = (ct - l[i] - r[i]);
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = i + 1; j < n; j++) if (ans[j] > ans[i]) c++;
        if (c != r[i]) {
            cout << "NO" << endl;
            return 0;
        }
        c = 0;
        for (int j = 0; j < i; j++) if (ans[j] > ans[i]) c++;
        if (c != l[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (auto &x : ans) cout << x << " ";
    cout << endl;
}