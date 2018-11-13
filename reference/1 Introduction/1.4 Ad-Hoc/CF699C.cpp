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

int solve(int day, int rest, int choice, vector<vi> &dp, const vi &a) {
    if (dp[day][choice] != -1) return dp[day][choice];
    if (choice == 0 or (a[day] & choice)) {
        int added_rest = (rest == 0 ? 1 : 0);
        if (day == 0) {
            dp[day][choice] = rest + added_rest;
        }
        else {
            dp[day][choice] = solve(day - 1, rest + added_rest, 0, dp, a);
            if (choice == 1) dp[day][choice] = min(dp[day][choice], solve(day - 1, rest + added_rest, 2, dp, a));
            else dp[day][choice] = min(dp[day][choice], solve(day - 1, rest + added_rest, 1, dp, a));
        }
    }
    else dp[day][choice] = rest + day;
    return dp[day][choice];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vi> dp(n, vi(3, -1));
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << min(
        solve(n - 1, 0, 0, dp, a),
        min(
            solve(n - 1, 0, 1, dp, a),
            solve(n - 1, 0, 2, dp, a)
        )
    );
    cout << endl;

    for (auto x : dp) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
}