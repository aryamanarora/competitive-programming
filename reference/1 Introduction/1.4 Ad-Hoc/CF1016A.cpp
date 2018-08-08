#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n = 0LL, m;
    cin >> n >> m;
    
    ll x, sum = 0LL, old = 0LL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << (sum + x) / m - old << " ";
        sum += x;
        old = sum / m;
    }

    cout << endl;
}