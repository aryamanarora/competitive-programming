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

const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k, d;
    ll dp[101][2] = {0};
    cin >> n >> k >> d;
    dp[0][0] = 1;
    for (int i = 0)
}

/*
3 3 2

0 1 2 3 4 5 6 7
0 0 1 2 0 0 0 0
*/