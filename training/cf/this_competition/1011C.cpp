#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <math.h>
#include <iomanip>

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
    ld n = 0, m;
    cin >> n >> m;
    vd a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ld weight = m * (b[0] / (b[0] - 1));
    for (int i = n - 1; i >= 1; i--) {
        weight *= (a[i] / (a[i] - 1));
        weight *= (b[i] / (b[i] - 1));
        if (isinf(weight)) {
            cout << "-1" << endl;
            return 0;
        }
    }
    weight = weight * (a[0] / (a[0] - 1));
    if (isinf(weight)) {
        cout << "-1" << endl;
        return 0;
    }
    cout << fixed << setprecision(10) << weight - m << endl;
}

/*
3 9
9
1: 3
2: 
*/