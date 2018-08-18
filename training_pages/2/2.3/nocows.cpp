/*
ID: aryaman4
TASK: nocows
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <complex>
#include <fstream>

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

const int MOD = 9901;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("nocows.in");
    int N, K; // nodes, depth
    fin >> N >> K;
    fin.close();

    ofstream fout("nocows.out");
    if (N % 2 == 0) {
        fout << 0 << endl;
        return 0;
    }

    // dp (bottom-up)
    int dp[201][101] = {0}; // dp[n][k]
    
    /**
     * base case: dp[0][...] = 1 (only one way to make tree with 0 nodes)
     * 
     * subtrees:
     *      left side: j nodes
     *      right side: n - j - 1 nodes
     * so dp[n][k] = dp[j][k-1] * dp[n-j-1][k-1] for all j in 0..n-1.
     */
    for (int i = 1; i <= K; i++) dp[1][i] = 1;
    for (int n = 3; n <= N; n += 2) {
        for (int k = 1; k <= K; k++) {
            for (int j = 1; j < n - 1; j += 2) {
                dp[n][k] += dp[j][k-1] * dp[n-j-1][k-1];
                dp[n][k] %= MOD;
            }
        }
    }
    fout << (dp[N][K] - dp[N][K-1] + MOD) % MOD << endl;
}

/*
depth->
0 1 2 3 4 5 6 7 8 9
1 1
3   1
5     2
7     1 4
9       6 8
11      6
13      4
15      1
17  
19  
21  
23  
27        28
29        8
31        1
33
*/

/*
8
7 + 6 + 5 + 4 + 3 + 2 + 1 = (7 * 8) / 2
*/
