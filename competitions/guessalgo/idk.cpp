#include <bits/stdc++.h>

using namespace std;

long long f(long long x) {
    if ((x % 8) == 0) return 0;
    return pow(2, ffs(x) - 1) + static_cast<long long>(pow(2, ffs(x / 8 + 1) - 1)) * 8 - 8;
}

long long g(long long x) {
    return (f(x) * 2) + 7;
}

int main() {
    long long n;
    while (true) {
        cin >> n;
        cout << g(n) << endl;
    }
}