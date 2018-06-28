#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    long long n, l;
    cin >> n >> l;
    vector<long long> a;

    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }

    a.push_back(0 - *min_element(a.begin(), a.end()));
    a.push_back(l + (l - *max_element(a.begin(), a.end())));

    sort(a.begin(), a.end());
    long long max_diff = 0;
    for (long long i = 0; i < n + 1; i++) max_diff = max(max_diff, a[i + 1] - a[i]);

    cout << setprecision(10) << (double) max_diff / 2 << "\n";
}