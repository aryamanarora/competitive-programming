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

    int n, p;
    cin >> n >> p;
    vi a(n), dp(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= p;
        if (i == 0) dp[i] = a[i];
        else dp[i] = max(a[i], a[i] + dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

/*
USE LONG LONG!!!!
*/