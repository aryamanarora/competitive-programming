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

typedef set<int> si;
typedef set<ii> sii;
typedef set<ld> sd;
typedef set<ll> sl;

typedef map<int, int> mii;
typedef priority_queue<int> pqi;
typedef queue<int> qi;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int MAXN = 200;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("paintbarn.in");
    ofstream cout("paintbarn.out");

    int n, k;
    cin >> n >> k;
    vector<vi> a(MAXN, vi(MAXN));

    for (int i = 0, x1, y1, x2, y2; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 < MAXN and y1 < MAXN) a[x1][y1]++;
        if (x1 < MAXN and y2 < MAXN) a[x1][y2]--;
        if (x2 < MAXN and y1 < MAXN) a[x2][y1]--;
        if (x2 < MAXN and y2 < MAXN) a[x2][y2]++;
    }

    int ct = 0;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (i > 0) a[i][j] += a[i - 1][j];
            if (j > 0) a[i][j] += a[i][j - 1];
            if (i > 0 and j > 0) a[i][j] -= a[i - 1][j - 1];
            if (a[i][j] == k) ct++;
        }
    }

    int ans = 0;

    // LEFT AND RIGHT
    vector<vi> dp1(MAXN, vi(MAXN));
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            dp1[i][j] = (a[i][j] == k - 1) - (a[i][j] == k);
            if (i > 0) dp1[i][j] += dp1[i - 1][j];
        }
    }

    vi left(MAXN), right(MAXN);
    for (int i = 0; i < MAXN; i++) {
        for (int j = i; j < MAXN; j++) {
            int cur = 0;
            for (int k = 0; k < MAXN; k++) {
                cur += (dp1[j][k] - (i == 0 ? 0 : dp1[i - 1][k]));
                left[k] = max(left[k], cur);
            }
            cur = 0;
            for (int k = MAXN - 1; k >= 0; k--) {
                cur += (dp1[j][k] - (i == 0 ? 0 : dp1[i - 1][k]));
                right[k] = max(right[k], cur);
            }
        }
    }

    for (int i = 1; i < MAXN; i++) left[i] = max(left[i], left[i - 1]);
    for (int i = MAXN - 2; i >= 0; i--) right[i] = max(right[i], right[i + 1]);
    
    ans = max(ans, max(right[0], left[MAXN - 1]));
    for (int i = 0; i < MAXN - 1; i++) ans = max(ans, left[i] + right[i + 1]);

    // UP AND DOWN
    // left right sums
    vector<vi> dp2(MAXN, vi(MAXN));
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            dp2[i][j] = (a[i][j] == k - 1) - (a[i][j] == k);
            if (j > 0) dp2[i][j] += dp2[i][j - 1];
        }
    }

    vi down(MAXN), up(MAXN);
    for (int i = 0; i < MAXN; i++) {
        for (int j = i; j < MAXN; j++) {
            int cur = 0;
            for (int k = 0; k < MAXN; k++) {
                cur += (dp2[k][j] - (i == 0 ? 0 : dp2[k][i - 1]));
                down[k] = max(down[k], cur);
            }
            cur = 0;
            for (int k = MAXN - 1; k >= 0; k--) {
                cur += (dp2[k][j] - (i == 0 ? 0 : dp2[k][i - 1]));
                up[k] = max(up[k], cur);
            }
        }
    }

    for (int i = 1; i < MAXN; i++) down[i] = max(down[i], down[i - 1]);
    for (int i = MAXN - 2; i >= 0; i--) up[i] = max(up[i], up[i + 1]);
    
    ans = max(ans, max(up[0], down[MAXN - 1]));
    for (int i = 0; i < MAXN - 1; i++) ans = max(ans, down[i] + up[i + 1]);

    cout << ct + ans << endl;
}