#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

int zeroes(int x) {
    int ans = 0;
    while (x % 10 == 0) {
        x /= 10;
        ans++;
    }
    return ans;
}

int main() {
    int n = 0;
    cin >> n;
    vector<vl> m(n, vl(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    string path = "";
    vector<vl> ans(n, vl(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0 and i > 0) m[i][j] *= m[i-1][j];
            else if (i == 0 and j > 0) m[i][j] *= m[i][j-1];
            else if (i != 0 and j != 0) {
                m[i][j] = ((zeroes(m[i][j] * m[i-1][j]) < zeroes(m[i][j-1] * m[i][j])) ? m[i][j] * m[i-1][j] : m[i][j-1] * m[i][j]);
            }
        }
    }
    cout << zeroes(m[n-1][n-1]);
}