#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int a = 0, d = 0;
    string ans;
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) ans.push_back(s[i]);
            else ans.insert(0, s[i]);
        }
    }
    else {
        ans.push_back(s[0]);
        for (int i = 1; i < n; i++) {
            if (i % 2 == 1) ans.push_back(s[i]);
            else ans.insert(0, s[i]);
        }
    }
    cout << ans << "\n";
}