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
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vi> dp(n, vi(5, -1));
    for (int i = 0; i < 5; i++) dp[0][i] = -2;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i] > a[i - 1]) {
                for (int k = 0; k < j; k++) {
                    if (dp[i - 1][k] != -1) {
                        dp[i][j] = k;
                        break;
                    }
                }
            }
            else if (a[i] < a[i - 1]) {
                for (int k = j + 1; k < 5; k++) {
                    if (dp[i - 1][k] != -1) {
                        dp[i][j] = k;
                        break;
                    }
                }
            }
            else {
                for (int k = 0; k < 5; k++) {
                    if (k == j) continue;
                    if (dp[i - 1][k] != -1) {
                        dp[i][j] = k;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        if (dp[n - 1][i] != -1) {
            deque<int> ans;
            int cur = i, pos = n - 1;
            while (dp[pos][cur] != -2) {
                ans.push_front(cur + 1);
                cur = dp[pos][cur];
                pos--;
            }
            ans.push_front(cur + 1);
            for (auto x : ans) cout << x << " ";
            cout << endl; 
            return 0;
        }
    }
    cout << -1 << endl;
}

/*
USE LONG LONG!!!!
*/