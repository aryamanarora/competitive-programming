#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, n_2 = 0, sum = 0, i = 0;
    cin >> n;
    
    for (; i < (long long) to_string(n).length(); i++) {
        long long x = 9 * (long long) pow(10, i);
        if (n_2 + x >= n) {
            n = n - n_2;
            break;
        }
        else {
            n_2 += x;
            sum += (i + 1) * x;
        }
    }
    sum += (i + 1) * n;
    

    cout << sum << "\n";
}