/*
ID: aryaman4
TASK: subset
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ll n = 0, sum = 0;
    ifstream fin("subset.in");
    fin >> n;
    fin.close();
    
    sum = (n * (n + 1)) / 2;

    if (sum % 2 != 0) {
        ofstream fout("subset.out");
        fout << "0\n";
        fout.close();
        return 0;
    }

    vector<vl> dp(n + 1, vl(sum / 2 + 1, 0));
    dp[0][0] = 1;

    for (auto x : dp) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
    cout << endl;

    for (int j = 0; j <= sum / 2; j++) {
        for (int i = 0; i <= n; i++) {
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j-i >= 0 and i > 0) dp[i][j] += dp[i-1][j-i];
        }
    }

    for (auto x : dp) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }

    ofstream fout("subset.out");
    fout << dp[n][sum/2]/2 << endl;
    fout.close();
}