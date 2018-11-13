#include <bits/stdc++.h>

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

int main() {
    int n, m;
    char x;
    cin >> n >> m >> x;

    vector<string> matrix;
    for (int i = 0; i < m; i++) {
        string a;
        cin >> a;
        matrix.pb(a);
    }

    set<char> desks;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == x) {
                if (j != 0) desks.insert(matrix[i][j-1]);
                if (j != n - 1) desks.insert(matrix[i][j+1]);
                if (i != m - 1) desks.insert(matrix[i+1][j]);
                if (i != 0) desks.insert(matrix[i-1][j]);
            }
        }
    }
    int ans = 0;
    for (auto i : desks) {
        if (i != x and i != '.') ans++;
    }
    cout << ans << "\n";
}