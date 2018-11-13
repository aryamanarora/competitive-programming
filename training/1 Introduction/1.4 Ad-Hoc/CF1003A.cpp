#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[101] = {0};

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    cout << *max_element(begin(a), end(a)) << "\n";
}