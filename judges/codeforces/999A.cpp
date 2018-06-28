#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, ans = 0;
    cin >> n >> k;

    vector<int> a;
    int (i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (a.back() <= k or a[0] <= k) {
        if (a.back() <= k) {
            ans++;
            a.pop_back();
        }
        else if (a[0] <= k) {
            ans++;
            a.erase(a.begin());
        }
    }
    cout << ans << "\n";
}