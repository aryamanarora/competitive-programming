/*
ID: aryaman4
TASK: ariprog
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m; // length of progression to search (dfs?) and upperbound of p and q inclusive
bool b[125001] = {false}; // all bisquares
set<pair<int, int>> ans; // answers

int search(int a, int diff) {
    for (int i = 1; i < n; i++) {
        if (a + i * diff > 125000) return 0;
        else if (b[a + i * diff] == false) return 0;
    }
    ans.insert(make_pair(diff, a));
    return 0;
}

int main() {
    ifstream fin("ariprog.in");
    fin >> n >> m;

    // generate all bisquares p^2 + q^2 such that 0 <= p, q <= m
    for (int i = 0; i <= m; i++) {
        for (int j = i; j <= m; j++) b[i * i + j * j] = true;
    }
    
    for (int i = 0; i < 125001; i++) {
        if (b[i] == true) {
            for (int j = 1; j <= (m * m * 2) / (n - 1) + 1; j++) {
                search(i, j);
            }
        }
    }
    ofstream fout("ariprog.out");
    if (ans.size() > 0) {
        for (auto x : ans) {
            if (x.first != 0) fout << x.second << " " << x.first << "\n";
        }
    }
    else fout << "NONE\n";
}