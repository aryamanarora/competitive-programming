/*
ID: aryaman4
TASK: kimbits
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

struct seq {
    int seq;
    int ones, len;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");

    ll n, l, i;
    fin >> n >> l >> i;
    i--;
    vector<vi> dp(l + 1, vi(n + 1, 0));
    dp[0][0] = 1;
    for (int x = 0; x <= l; x++) {
        for (int y = x; y <= n; y++) {
            if (y > 0) {
                dp[x][y] += dp[x][y - 1];
                if (x > 0) dp[x][y] += dp[x - 1][y - 1];
            }
        }
    }
    for (int x = 1; x <= l; x++) {
        for (int y = x; y <= n; y++) {
            dp[x][y] += dp[x - 1][y];
        }
    }

    int ones = l;
    for (int bit = n; bit > 0; bit--) {
        cout << i << ": " << bit << " " << ones << " " << dp[ones][bit - 1] << endl;
        ones = min(ones, bit - 1);
        if (dp[ones][bit - 1] > i) {
            fout << 0;
        }
        else {
            fout << 1;
            i -= dp[ones][bit - 1];
            ones--;
        }
    }
    fout << endl;

    fin.close();
    fout.close();
}