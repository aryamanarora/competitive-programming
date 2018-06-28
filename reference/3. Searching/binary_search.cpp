#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 6;
    int arr[6] = {1, 5, 9, 3, 2, 10};

    sort(begin(arr), end(arr)); // iterators for C-style arrays, use .begin() and .end() methods for vectors
    int x = 3; // what we are looking for

    int a = 0, b = n - 1;
    while (a <= b) {
        int k = (a + b) / 2;
        if (arr[k] == x) {
            cout << k << "\n"; // we found it!
        }
        if (arr[k] < x) a = k + 1;
        else b = k - 1;
    }
}