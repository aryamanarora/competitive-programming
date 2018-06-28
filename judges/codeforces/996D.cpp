#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    n *= 2;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int ans = 0;
    // try i
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] == i) {
                if 
            }
        }
    }

    cout << ans << "\n";
}
