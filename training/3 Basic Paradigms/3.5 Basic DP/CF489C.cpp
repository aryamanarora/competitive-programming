#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, s;
    cin >> m >> s;
    ss = s;
    if (s > 9 * m or s < 1) {
        cout << "-1 -1" << endl;
        return 0;
    }

    string max_ans, min_ans;
    while (s >= 9 and max_ans.length() < m) {
        max_ans.pb('9');
        s -= 9;
    }
    if (s >= 0 and max_ans.length() != m) {
        max_ans.pb(s);
        s = 0;
    }
    while (max_ans.length() < m) {
        max_ans.pb('0');
    }

    if (max_ans.back() != '0') {
        min_ans = max_ans;
        reverse(min_ans.begin(), min_ans.end());
        cout << min_ans << " " << max_ans << endl;
        return 0;
    }
    else {
        while (s >= 9 and min_ans.length() < m) {
            min_ans.pb('9');
            s -= 9;
        }
        if (s >= 0 and max_ans.length() < m - 1) {
            max_ans.pb(s - 1);
            s = 1;
        }
        if (max_ans.length() < m - 1) {
            max_ans.pb('0');
        }
        if (s == 1 and max_ans.length() == m - 1) max_ans.pb('1');
        reverse(min_ans.begin(), min_ans.end());
        cout << min_ans << " " << max_ans << endl;
        return 0;
    }
}