#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    vector<pair<char, int>> t;
    for (int i = 0; i < n; i++) {
        t.push_back(make_pair(s[i], i));
    }

    sort(t.begin(), t.end());
    t.erase(t.begin(), t.begin() + k);
    sort(t.begin(), t.end(), [](const pair<char, int>& a, const pair<char, int>& b)
    {
        return a.second < b.second;
    });
    
    for (auto x : t) {
        cout << x.first;
    }
    cout << "\n";
}