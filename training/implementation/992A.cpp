#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 0) {
            a.push_back(x);
        }
    }

    set<int> b(a.begin(), a.end());
    cout << b.size() << "\n";
}