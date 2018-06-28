#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll x, k;
    cin >> x >> k;
    k++;
    
    if (k == 1) {
        cout << x * 2 << endl;
        return 0;
    }

    ll y = x; // lower bound of dresses
    
    while (k > 0) {
        x *= 2;
        if (x > 1000000007) {
            x = x % 1000000007;
        }
        if (y > 1000000007) {
             = y % 1000000007;
        }
        if (k != 1) {
            y--;
        }
        k--;
    }
    cout << (x + y)/2 << endl;
}