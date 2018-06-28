/*
ID: aryaman4
TASK: skidesign
LANG: C++11         
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("skidesign.in");
    int N;
    fin >> N;

    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        fin >> x[i];
    }

    sort(x.begin(), x.end());
    int min_price = 1000000000;

    for (int i = 0; i <= 100; i++) {
        int j = i + 17;
        if (j > x[N - 1]) {
            break;
        }
        int price = 0;
        for (auto y : x) {
            if (y < i and y < j) {
                price += (i - y) * (i - y);
            }
            else if (y > j) {
                price += (y - j) * (y - j);
            }
        }
        min_price = min(price, min_price);
    }

    ofstream fout("skidesign.out");
    fout << min_price << "\n";
}