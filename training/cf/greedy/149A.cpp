#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    vector<int> a;

    cin >> k;
    for (int i = 0; i < 12; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.rbegin(), a.rend());
    int ans, t = 0;
    for (int i = 0; i < 12 && t < k; i++) {
        t += a[i];
        ans++;
    }
    
    cout << ans << "\n";
}