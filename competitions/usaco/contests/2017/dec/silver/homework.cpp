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

    ifstream cin("homework.in");
    ofstream cout("homework.out");

    int n;
    cin >> n;
    vd a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vd mini(n), sum(n);
    mini[n - 1] = a[n - 1];
    sum[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        mini[i] = min(mini[i + 1], a[i]);
        sum[i] = sum[i + 1] + a[i];
    }

    ld ct = static_cast<double>(n - 2);
    vector<pair<int, ld>> ans;
    ans.pb({1, (sum[1] - mini[1]) / ct});
    // cerr << 1 << " " << sum[1] - mini[1] << endl;
    pair<int, ld> cur;
    for (int i = 2; i < n - 1; i++) {
        ct -= 1.0;
        cur = {i, (sum[i] - mini[i]) / ct};
        if (abs(cur.s - ans[0].s) <= 1e-9) {
            ans.pb(cur);
        }
        else if (cur.s - ans[0].s > 1e-9) {
            ans.clear();
            ans.pb(cur);
        }
        // cerr << i << " " << sum[i] - mini[i] << endl;
    }

    for (auto x : ans) cout << x.f << endl;
}

/*
USE LONG LONG!!!!
*/