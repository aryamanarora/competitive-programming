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

const int MAX = 100001;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k;
    cin >> t >> k;

    vi dp(MAX, 0);
    dp[0] = 1;
    for (int i = 1; i < MAX; i++) {
        if (i < k) dp[i] = dp[i-1];
        else dp[i] = dp[i-1] + dp[i-k];
        dp[i] %= MOD;
    }
    for (int i = 1; i < MAX; i++) {
        dp[i] += dp[i-1];
        dp[i] %= MOD;
    }

    int a, b;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << (dp[b] + MOD - dp[a - 1]) % MOD << endl;
    }
}