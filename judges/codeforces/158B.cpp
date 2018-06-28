#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s (4);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s[x]++;
    }
    
    int ans = 0;
    
    // ones
    ans += s[0] / 4;
    s[0] = s % 4;
    // twos
    ans += s[1] / 2;
    s[1] = s % 2;
    // fours
    ans += s[3];
    s[3] = 0;
    // twos and ones
    if (s[0] == 2 and s[1] > 0) {
        s[1]--;
        s[0] = 0;
        ans += 1;
    }
    // three and ones
    if (s[0] == 1 and s[2] > )

    cout << ans << "\n";

}