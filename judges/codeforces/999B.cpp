#include <bits/stdc++.h>

using namespace std;

vector<int> divisors(int x) {
    vector<int> divs;
    
    for (int i = 1; i <= (x + 1) / 2; i++) {
        if (x % i == 0) {
            divs.push_back(i);
        }
    }
    divs.push_back(x);
    return divs;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (auto x : divisors(n)) {
        reverse(s.begin(), s.begin() + x);
    }

    cout << s << "\n";
}