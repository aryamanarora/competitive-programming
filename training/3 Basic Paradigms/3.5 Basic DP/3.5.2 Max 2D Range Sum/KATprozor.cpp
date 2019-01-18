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

    int r, s, k;
    char m;
    cin >> r >> s >> k;
    vector<vi> a(r, vi(s)), dp(r, vi(s));
    int ans = 0, x, y;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            cin >> m;
            dp[i][j] = a[i][j] = (m == '*' ? 1 : 0);
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
            if (i > 0 and j > 0) dp[i][j] -= dp[i - 1][j - 1];
            if (i >= k - 1 and j >= k - 1) {
                if (dp[i - 1][j - 1] - dp[i - k + 1][j - 1] - dp[i - 1][j - k + 1] + dp[i - k + 1][j - k + 1] > ans) {
                    ans = dp[i - 1][j - 1] - dp[i - k + 1][j - 1] - dp[i - 1][j - k + 1] + dp[i - k + 1][j - k + 1];
                    x = i, y = j;
                }
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            if ((i == x - k + 1 and j == y - k + 1) or
                (i == x - k + 1 and j == y) or
                (i == x and j == y - k + 1) or
                (i == x and j == y)) cout << "+";
            else if ((i == x - k + 1 or i == x) and j > y - k + 1 and j < y) cout << "-";
            else if ((j == y - k + 1 or j == y) and i > x - k + 1 and i < x) cout << "|";
            else if (a[i][j] == 1) cout << "*";
            else cout << ".";
        }
        cout << endl;
    }
}

/*
USE LONG LONG!!!!
*/