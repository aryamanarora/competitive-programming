#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main () {
    long long n;
    cin >> n;

    vector<long long> fl;
    long long max = 0, min = 1000000000;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        fl.push_back(x);
        if (x > max) {
            max = x;
        }
        if (x < min) {
            min = x;
        }
    }

    long long max_beauty_difference = max - min;
    long long mins = 0, maxs = 0, perms;
    if (min != max) {
        for (int i = 0; i < n; i++) {
            if (fl[i] == min) {
                mins++;
            }
            if (fl[i] == max) {
                maxs++;
            }
        }
        perms = mins * maxs;
    }
    else {
        perms = (n * (n - 1) / 2); // 2-combinations of the set
    }

    cout << max_beauty_difference << " " << perms << endl;
}