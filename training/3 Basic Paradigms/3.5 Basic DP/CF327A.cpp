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

    int n = 0, ct = 0;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            a[i] = -1;
            ct++;
        }
        else a[i] = 1;
    }
    vi dp(n);
    dp[0] = a[0];
    int ans = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }

    cout << ct + ans << endl;
}