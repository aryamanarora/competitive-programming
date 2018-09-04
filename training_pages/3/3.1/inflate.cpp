/*
ID: aryaman4
TASK: inflate
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

const int MAX = 10001;

int m, n;
vii problems;
vl dp(MAX, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    fin >> m >> n;
    
    int value, weight;
    while (n--) {
        fin >> value >> weight;
        for (int i = weight; i <= m; i++) {
            dp[i] = max(dp[i], dp[i - weight] + value);
        }
    }
    fout << dp[m] << endl;

    fin.close();
    fout.close();
}