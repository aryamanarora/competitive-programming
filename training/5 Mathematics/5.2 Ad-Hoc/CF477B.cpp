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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    ll smol_ans = 0, big_ans = ((n - m + 1) * (n - m)) / 2;
    ll smol_fac = n / m;
    smol_ans += (n % m) * ((smol_fac * (smol_fac + 1)) / 2);
    smol_ans += (m - n % m) * ((smol_fac * (smol_fac - 1)) / 2);
    cout << smol_ans << " " << big_ans << endl;
}