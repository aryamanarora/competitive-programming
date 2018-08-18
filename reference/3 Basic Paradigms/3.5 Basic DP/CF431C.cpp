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

const ll MOD = 1000000007;

template<typename T>
void addmod(T &a, T b) {
    a += b;
    a %= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k, d;
    ll dp[101][2] = {0};
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;

    int mod0 = 0, mod1 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j < 0) break;
            if (j < d) {
                addmod(dp[i][0], dp[i-j][0]);
                addmod(dp[i][1], dp[i-j][1]);
            }
            else
            {
                addmod(dp[i][1], dp[i-j][0]);
                addmod(dp[i][1], dp[i-j][1]);
            }
        }
    }

    cout << dp[n][1] << endl;
}

/*
3 3 2

0 1 2 3 4 5 6 7
0 0 1 2 0 0 0 0
*/