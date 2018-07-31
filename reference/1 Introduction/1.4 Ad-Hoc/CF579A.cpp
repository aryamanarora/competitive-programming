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
    ll x;
    cin >> x;
    string y = bitset<32>(x).to_string();
    int ans = 0;
    for (char &x : y) {
        if (x == '1') ans++;
    }
    cout << ans << "\n";
}