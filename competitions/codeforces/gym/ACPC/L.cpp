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

ifstream fin("looking.in");

void solve() {
    int n, k;
    fin >> n >> k;
    vector<vi> dp(k, vi(n));
    for (int i = 0; i < n; i++) {
        fin >> dp[0][i];
    }
    int maxi = 0;
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                dp[i][j] = max(dp[0][i] | dp[i - 1][l], dp[i][j]);
            }
            if (i == k - 1) maxi = max(maxi, dp[i][j]);
        }
    }
    /*
    for (auto x : dp) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
    */
    cout << maxi << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    fin >> t;
    while (t--) {
        solve();
    }
}

/*
USE LONG LONG!!!!
*/