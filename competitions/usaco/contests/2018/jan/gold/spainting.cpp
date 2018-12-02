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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("spainting.in");
    ofstream fout("spainting.out");

    int n, m, k;
    fin >> n >> m >> k;
    vl dp(n, 0);
    vl mpow(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        mpow[i] = (mpow[i - 1] * m) % MOD;
    }
    ll ans = 0, cur;
    for (int i = 0; i <= n - k; i++) {
        // cout << i << ": ";
        cur = mpow[n - i - k + 1];
        // cout << ans << " ";
        cur %= MOD;
        if (i >= 1) {
            cur *= (m - 1);
            cur %= MOD;
            // cout << ans << " ";
            cur *= mpow[i - 1];
            cur %= MOD;
            // cout << ans << " ";
        }
        ans += cur;
        ans %= MOD;
        // cout << ans << endl;
    }
    // cout << ans << endl;
    fout << ans << endl;
}

/*
USE LONG LONG!!!!

4 3 3
AAA[A/B/C] [B/C]AAA
3 * 3^1 + 3 * 2^1
m * m^(n - i - k) + m * (m - 1)^i
*/