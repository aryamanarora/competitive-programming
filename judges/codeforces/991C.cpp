#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
int main() {
    long long m;
    cin >> m;

    for (long long k = 1; k <= m; k++) {
        long long n = m;
        long long vasya = 0;
        while (n >= k) {
            n -= k;
            vasya += k;
            n -= n / 10;
        }
        vasya += n;
        if (vasya >= (double) m / 2.0) {
            cout << k << "\n";
            return 0;
        }
    }
}
*/

int main() {
    long long m;
    cin >> m;

    vector<long long> ans;

    long long a = 1, b = m;
    while (a <= b) {
        long long k = (a + b) / 2;
        long long n = m;
        long long vasya = 0;
        while (n >= k) {
            n -= k;
            vasya += k;
            n -= n / 10;
        }
        vasya += n;
        if (vasya >= (double) m / 2.0) {
            ans.push_back(k);
            b = k - 1;
        }
        else a = k + 1;
    }

    cout << *min_element(ans.begin(), ans.end()) << "\n";
}