/*
ID: aryaman4
TASK: numtri
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
int r;
int max_sum = 0;
int sum = 0;

int main() {
    ifstream fin("numtri.in");
    fin >> r;

    // fill tree
    for (int i = 0; i < r; i++) {
        vector<int> x(i+1);
        for (int j = 0; j <= i; j++) {
            fin >> x[j];
            if (j == 0 and i > 0) x[j] += tree[i-1][j];
            else if (j == i and i > 0) x[j] += tree[i-1][j-1];
            else if (i > 0) x[j] += max(tree[i-1][j], tree[i-1][j-1]);
        }
        tree.push_back(x);
    }

    ofstream fout("numtri.out");
    fout << *max_element(tree[r-1].begin(), tree[r-1].end()) << "\n";
}