#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    float n, total = 0.0;
    cin >> n;

    vector<float> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        total += g[i];
    }

    if (round(total / n) >= 5) {
        cout << "0\n";
        return 0;
    }

    sort(g.begin(), g.end());

    int ans = 0;
    for (auto x : g) {
        total += 5 - x;
        ans++;
        if (round(total / n) == 5) {
            cout << ans << "\n";
            return 0;
        }
    }
}