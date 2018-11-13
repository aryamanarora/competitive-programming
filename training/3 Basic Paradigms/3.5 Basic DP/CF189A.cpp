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

    int n = 0, a, b, c;
    cin >> n >> a >> b >> c;

    vi dp(n + 1);
    dp[0] = 0; // base case
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
        if (i - a >= 0) dp[i] = max(dp[i], dp[i-a]);
        if (i - b >= 0) dp[i] = max(dp[i], dp[i-b]);
        if (i - c >= 0) dp[i] = max(dp[i], dp[i-c]);
        if (dp[i] != -1) dp[i]++;
    }
    cout << dp[n] << endl;
}