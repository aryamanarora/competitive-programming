#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n]; // sequence
    int b[m]; // fingerprints

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        int x = a[i];

        for (int j = 0; j < m; j++) {
            if (b[j] == x) {
                cout << x << " ";
            }
        }
    }
    cout << endl;
}