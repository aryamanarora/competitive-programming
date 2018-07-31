#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans;
    int price = pow(10, 6);

    for (int i = 0; i < n; i++) {
        int a, p;
        cin >> a >> p;
        
        if (p < price) price = p;
        ans += a * price;
    }

    cout << ans << "\n";
}