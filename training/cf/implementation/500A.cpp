#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> c;
    int n, t;

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c.push_back(x);
    }

    int pos = 1;
    while (true) {
        if (pos == t) {
            cout << "YES\n";
            return 0;
        }
        if (pos > t) break;
        pos += c[pos - 1];
    }
    cout << "NO\n";
    return 0;
}