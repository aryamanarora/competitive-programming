#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int a = 0, d = 0;
    for (auto x : s) {
        if (x == "A") a++;
        else d++;
    }
    if (a == d) cout << "Friendship";
    else if (a > d) cout << "Anton";
    else cout << "Danik";
    cout << "\n";
}