#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i % 3] += x; 
    }

    int ans = distance(a, max_element(a.begin(), a.end()));
    if (ans == 0) cout << "chest\n";
    else if (ans == 1) cout << "biceps\n";
    else cout << "back\n";
    return 0;
}