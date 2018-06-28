#include <bits/stdc++.h>

using namespace std;

vector<int> n;

int main() {
    string s;
    cin >> s;
    for (auto x : s) {
        n.push_back((int) x);
    }
    sort(n.begin(), n.end());

    int ans = 0;

    do {
        if (n[0] != 0) {
            ans++;
        }
    } while (next_permutation(n.begin(), n.end()));

    cout << ans << "\n";
}