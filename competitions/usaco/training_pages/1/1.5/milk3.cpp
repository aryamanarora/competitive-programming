/*
ID: aryaman4
TASK: milk3
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

#define MAX 21

using namespace std;

set<int> ans_set;

int A, B, C;
int t[MAX][MAX][MAX] = {false};

int dfs(int a, int b, int c) {
    if (a == 0) ans_set.insert(c);
    if (t[a][b][c]) return 0;
    t[a][b][c] = true;

    int d = min(B - b, a);
    if (d != 0) dfs(a - d, b + d, c);

    d = min(C - c, a);
    if (d != 0) dfs(a - d, b, c + d);

    d = min(A - a, b);
    if (d != 0) dfs(a + d, b - d, c);

    d = min(C - c, b);
    if (d != 0) dfs(a, b - d, c + d);

    d = min(B - b, c);
    if (d != 0) dfs(a, b + d, c - d);

    d = min(A - a, c);
    if (d != 0) dfs(a + d, b, c - d);
    return 0;
}

int main() {
    ifstream fin("milk3.in");
    fin >> A >> B >> C;
    dfs(0, 0, C);
    
    vector<int> ans(ans_set.begin(), ans_set.end());

    ofstream fout("milk3.out");
    for (int i = 0; i < ans.size() - 1; i++) {
        fout << ans[i] << " ";
    }
    fout << ans[ans.size() - 1] << "\n";
}