#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    k = 240 - k;
    int mins = 0, ans = 0;
    for (int i = 1; i <= n and mins <= k; i++) {
        mins += i * 5;
        ans++;
    }
    if (mins > k) ans--;
    cout << ans << "\n";
}