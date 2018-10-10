#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <complex>

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m;
    vector<vi> a(m, vi(n));
    for (int i = 0; i < n; i++) cin >> a[0][i];
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            cin >> x;
            a[0][0] *= x;
        }
        else cin >> a[m][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            a[j][i] = a[j][0] * a[i][0];
            a[j][i] += a[j][i-1];
        }
    }
}