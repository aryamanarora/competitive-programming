#include <iostream>
#include <algorithm>

using namespace std;

int ans = 1000000000;
int n, m;
int t = 0;

int search(int a, bool op) {
    cout << a << "\n";
    if (a >= 2 * m) {
        ans = min(ans, t + (a - m));
        t--;
        return 0;
    }
    else if (a == m) {
        ans = min(ans, t);
        return 0;
    }

    if (op == true) {
        t++;
        search(a * 2, true);
        search(a * 2, false);
    }
    else {
        t++;
        search(a - 1, true);
        search(a - 1, false);
    }
}

int main() {
    cin >> n >> m;

    search(n, true);
    search(n, false);

    cout << ans << "\n";
}