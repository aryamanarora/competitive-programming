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

    ll l, r;
    cin >> l >> r;
    if (l == r or abs(l - r) == 1) {
        cout << (l ^ r) << endl;
        return 0;
    }

    while (static_cast<int>(log2(l)) == static_cast<int>(log2(r))) {
        ll x = static_cast<int>(log2(l));
        x = pow(2, x);
        l -= x;
        r -= x;
    }
    if (l < r) swap(l, r);

    ll x = static_cast<int>(log2(l));
    x = pow(2, x + 1) - 1;
    cout << x << endl;
}

/*
USE LONG LONG!!!!
*/