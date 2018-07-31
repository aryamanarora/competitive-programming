#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long cost(vector<long long> t, long long l) {
    long long ans = 0;
    long long diff = t.back() - t[0];

    ans = (120 * (long long) floor(diff / 1440));
    ans = min(ans, (long long) (50 * floor(diff / 90)));
    ans = min(ans, 20 * l);
    return ans;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> t;
    long long total = 0;
    long long l = 0;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        t.push_back(x);
        l++;
        cout << cost(t, l) - total << "\n";
        total = cost(t, l);
    }
}