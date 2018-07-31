#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        if (x > y) cout << ">" << endl;
        else if (x < y) cout << "<" << endl;
        else cout << "=" << endl;
    }
}