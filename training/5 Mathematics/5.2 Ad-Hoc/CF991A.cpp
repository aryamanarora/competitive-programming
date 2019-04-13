#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    int pass = a + b - c;
    int fail = n - pass;
    if (fail < 1 or a < 0 or b < 0 or c < 0 or a > n or b > n or c > n or c > a or c > b or n < 0 or pass < 0 or n < pass) {
        cout << "-1\n";
        return 0;
    }

    cout << fail << "\n";
    return 0;
}