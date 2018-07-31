/*
ID: aryaman4
TASK: hamming
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <functional>
#include <bitset>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

#define MAX 256

int n, b, d;
vector<vi> matrix(MAX, vi(MAX, 0));
int component[MAX] = {0};

int hamming(int x, int y) {
    int ans = 0;
    x = x ^ y;
    while (x)
    {
      x &= (x-1) ;
      ans++;
    }
    return ans;
}

int main() {
    ifstream fin("hamming.in");
    fin >> n >> b >> d;

    b = pow(2, b);
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            matrix[i][j] = (hamming(i, j) >= d ? 1 : 0);
        }
    }

    vi ans;
    ans.pb(0);
    for (int i = 1; i < b; i++) {
        bool okay = true;
        if (ans.size() == n) break;
        for (auto x : ans) {
            if (matrix[i][x] == 0) {
                okay = false;
                break;
            } 
        }
        if (okay) ans.pb(i);
    }
    
    ofstream fout("hamming.out");
    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];
        if (i % 10 == 9 or i == ans.size() - 1) fout << "\n";
        else fout << " ";
    }
}