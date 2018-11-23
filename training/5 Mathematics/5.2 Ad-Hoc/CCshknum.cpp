#include <iostream>
#include <vector>
#include <complex>
#include <functional>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

#define LIM 30 // 2^29 + 2^30 > 1e9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vi check;
    for (int i = 0; i <= LIM; i++) {
        for (int j = i + 1; j <= LIM; j++) {
            check.pb(pow(2, i) + pow(2, j));
        }
    }

    sort(check.begin(), check.end());

    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        int f = 0, l = check.size() - 1, mid;
        while (f <= l) {
            mid = (f + l) / 2;
            if (check[mid] == a) break;
            else if (check[mid] > a) l = mid - 1;
            else f = mid + 1;
        }
        if (check[mid] < a) mid++;
        if (a >= 3) {
            cout << min(abs(check[mid] - a), abs(check[mid - 1] - a)) << endl;
        }
        else {
            cout << abs(check[0] - a) << endl;
        }
    }
}