#include <iostream>

using namespace std;

int main() {
    long long n, ans = 0;
    cin >> n;

    if (n >= 100) {
        ans += n / 100;
        n %= 100;
    }
    if (n >= 20) {
        ans += n / 20;
        n %= 20;
    }
    if (n >= 10) {
        ans += n / 10;
        n %= 10;
    }
    if (n >= 5) {
        ans += n / 5;
        n %= 5;
    }
    if (n >= 1) {
        ans += n;
        n = 0;
    }

    cout << ans << "\n";
}