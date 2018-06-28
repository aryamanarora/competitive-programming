#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
vi subset;

void search(int k, vi subsets, int n) {
    if (k == n) {
        cout << "( ";
        for (auto x : subset) {
            cout << x << " ";
        }
        cout << " )\n";
    }
    else {
        search(k+1, subsets, n);
        subset.push_back(subsets[k]);
        search(k+1, subsets, n);
        subset.pop_back();
    }
}

int main() {
    vi subsets;
    subsets.push_back(1);
    subsets.push_back(2);
    subsets.push_back(3);
    search(0, subsets, subsets.size());
    return 0;
}