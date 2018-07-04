#include <bits/stdc++.h>

using namespace std;

int main() {
    int x = 0, y = 0;
    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        x += a;
    }
    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        y += a;
    }
    int n;
    cin >> n;

    x = ceil(x / 5.0);
    y = ceil(y / 10.0);

    if (x + y > n) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}