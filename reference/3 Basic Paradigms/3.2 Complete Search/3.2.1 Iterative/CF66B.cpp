#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    int ans = 1;
    for (int i = 0; i < n; i++) {
        int w = 1;
        int min = h[i];
        for (int j = i - 1; j >= 0; j--) {
            if (h[j] <= min) {
                w++;
                min = h[j];
            }
            else break;
        }
        min = h[i];
        for (int j = i + 1; j < n; j++) {
            if (h[j] <= min) {
                w++;
                min = h[j];
            }
            else break;
        }
        ans = max(w, ans);
    }

    cout << ans << "\n";
}