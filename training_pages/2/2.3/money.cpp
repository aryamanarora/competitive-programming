/*
ID: aryaman4
TASK: money
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <complex>

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("money.in");
    ll V = 0, N;
    fin >> V >> N;
    vl coins(V);
    for (int i = 0; i < V; i++) fin >> coins[i];
    fin.close();

    ll dp[MAX] = {0};
    dp[0] = 1;
    for (auto &c : coins) {
        for (int i = c; i <= N; i++) {
            dp[i] += dp[i-c];
        }
    }

    ofstream fout("money.out");
    fout << dp[N] << endl;
    fout.close();
}