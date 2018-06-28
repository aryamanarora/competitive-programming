#include <bits/stdc++.h>

using namespace std;

int main() {
    long long m, s;
    cin >> m >> s;
    long long s_2 = s;

    long long base = 0;

    if (s > m * 9 or s == 0 or m < s) {
        cout < "-1 -1\n";
        return 0;
    }

    long long min_ans = 0, max_ans = 0;
    while (s > 9) {
        s -= 9;
        min_ans += s * pow(10, base);
        base++;
    }

    cout << min_ans << " " << max_ans << "\n";
}