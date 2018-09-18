/*
ID: aryaman4
TASK: stamps
LANG: C++14
*/

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

    ifstream fin("stamps.in");
    ofstream fout("stamps.out");

    int k, n;
    fin >> k >> n;

    vi coins(n);
    for (int i = 0; i < n; i++) fin >> coins[i];

    ll limit = *max_element(coins.begin(), coins.end()) * k + 1;

    vi dp(limit, -1);
    dp[0] = 0;
    for (auto &x : coins) {
        for (int i = x; i < limit; i++) {
            if (dp[i-x] != -1) {
                if (dp[i] == -1) dp[i] = dp[i-x] + 1;
                else dp[i] = min(dp[i-x] + 1, dp[i]);
            }
        }
    }

    for (int i = 1; i < limit; i++) {
        if (dp[i] > k) {
            fout << i - 1 << endl;
            return 0;
        }
    }
    fout << limit - 1 << endl;

    fin.close();
    fout.close();
}