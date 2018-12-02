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

ll val(ll i) {
    return (i % 2 ? -1 : 1) * ((i / 2) + i % 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;
    ll l, r;
    while (q--) {
        cin >> l >> r;
        cout << val(r) - val(l - 1) << endl;
    }
}

/*
USE LONG LONG!!!!
*/