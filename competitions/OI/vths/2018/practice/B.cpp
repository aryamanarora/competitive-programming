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

ll hamming(ll x, ll y) {
    ll ans = 0;
    x = x ^ y;
    while (x)
    {
      x &= (x-1) ;
      ans++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin >> a >> b;
    cout << hamming(a, b) << endl;
}

/*
USE LONG LONG!!!!
*/