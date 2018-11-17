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

    int n, a;
    cin >> n;
    vector<vi> dp(n, vi(3));
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) dp[i] = {1, 1, 1};
        else if (a == 1) dp[i] = {1, 0, 1};
        else if (a == 2) dp[i] = {1, 1, 0};
        else dp[i] = {1, 0, 0};
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] += min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
    }
    
    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
}