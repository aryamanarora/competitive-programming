#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <bitset>

using namespace std;

int main() {
    int ans = 0;
    int n, m;
    cin >> n >> m;

    while (m > n) {
        if (m % 2) {
            m--;
            ans++;
        }
        else {
            m /= 2;
            ans++;
        }
    }
    if (n >= m) {
        ans += n - m;
    }

    cout << ans << "\n";
}