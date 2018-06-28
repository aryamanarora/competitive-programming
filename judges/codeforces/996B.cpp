#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long n, ans = 0;
    cin >> n;
    
    vector<long long> q;
    for (long long j = 0; j < n; j++) {
        long long x;
        cin >> x;
        q.push_back(x - j);
    }
    
    long long red = ceil((double) *min_element(q.begin(), q.end()) / (double) n) * n;
    for (long long j = 0; j < n; j++) {
        if (q[j] - red <= 0) {
            ans = j + 1;
            break;
        }
    }

    cout << ans << "\n";
}