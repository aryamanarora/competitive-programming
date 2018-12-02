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

ll op(ll n, ll l, ll r) {
    if (n == 0) return 0;
    ll len = pow(2LL, static_cast<ll>(log2(n))) - 1LL;
    if (l < len and r < len) return op(n / 2, l, r);
    if (l < len and r == len) return op(n / 2, l, r) + n % 2;
    if (l > len and r > len) return op(n / 2, l - len - 1, r - len - 1);
    if (l == len and r > len) return op(n / 2, l - len - 1, r - len - 1) + n % 2;
    if (l < len and r > len) return op(n / 2, l, len - 1) + op(n / 2, 0, r - len - 1) + n % 2;
    if (l == len and r == len) return n % 2;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, l, r;
    cin >> n >> l >> r;
    l--; r--;

    cout << op(n, l, r) << endl;
}

/*
USE LONG LONG!!!!
*/