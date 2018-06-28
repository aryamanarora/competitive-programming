#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x % m, x);
    }

    sort(a.begin(), a.end());
    
}