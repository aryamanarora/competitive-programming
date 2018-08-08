/*
ID: aryaman4
TASK: nocows
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

    ifstream fin("nocows.in");
    int n, k;
    fin >> n >> k;

    ofstream fout("nocows.out");
    if (n % 2 == 0) {
        fout << 0 << endl;
        return 0;
    }

    int dp[200][100]; // dp[n][k]
    memset()
}

/*
layers->
0 2 3 4 5 6 7 8 9
3 1
5   2
7   1 4
9     6 8
11    6
13    4
15    1
17
19
21
23
27      28
29      8
31      1
33
*/

/*
8
7 + 6 + 5 + 4 + 3 + 2 + 1
*/
