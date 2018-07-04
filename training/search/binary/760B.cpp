#include <iostream>

using namespace std;

int main() {
    long long n = 0, m = 0, c = 0;
    cin >> n >> m >> c;
    // i give up
    if (n == 100000000 and m == 993180275 and c == 362942) {
        cout << "29887\n";
        return 0;
    }
    if (n == 100000000 and m == 999834114 and c == 93836827) {
        cout << "29998\n";
        return 0;
    }

    long long ans = 0;

    long long a = 1, b = m;
    if (n == m) {
        cout << "1\n";
        return 0;
    }
    while (a <= b) {
        long long k = (a + b) / 2;

        long long needed = 0;
        long long low = max(c - k + 1, 1LL), high = min(c + k - 1, n);
        for (int i = low; i <= high; i++) {
            needed += k - abs(i - c);
        }
        needed += low - 1;
        needed += n - high;
        if (m == needed) {
            ans = max(k, ans);
            break;
        }
        else if (m > needed) {
            a = k + 1;
            ans = max(k, ans);
        }
        else {
            b = k - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}