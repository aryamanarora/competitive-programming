#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> f;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f.push_back(x);
    }

    vector<pair<int, int>> likes;
    for (int i = 0; i < n; i++) {
        likes.push_back(make_pair(x[i], x[x[i] - 1]));
    }

    for (auto y : likes) {
        int start = y.first, pos = y.first, i = 0;
        for (int i = 0; i < 3 && pos != y; i++) {
            pos = y.second;
            y = likes[pos - 1];
        }
        if (pos == start && i == 2) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}