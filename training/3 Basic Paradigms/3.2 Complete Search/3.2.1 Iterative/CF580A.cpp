#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

int main() {
    ll n = 0LL;
    cin >> n;
    ll prev;
    cin >> prev;
    ll cur;
    int ans = 0, length = 1;
    for (int i = 1; i < n; i++) {
        cin >> cur;
        if (cur >= prev) length++;
        else {
            ans = max(ans, length);
            length = 1;
        }
        prev = cur;
    }
    ans = max(ans, length);
    cout << ans << "\n";
}