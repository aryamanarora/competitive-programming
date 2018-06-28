#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> b, g;
map<

int search() {

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        g.push_back(x);
    }

    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    int ans = search();
    cout << ans << "\n";
}