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
    ll m, n;
    cin >> m >> n;
    vl pattern;
    for (int i = 0; i < n; i++) {
        cout << "1" << endl;
        ll get;
        cin >> get;
        if (get == 0) {
            return 0;
        }
        else {
            pattern.pb(get);
        }
    }
    ll a = 0, b = m;
    int ct = 0;
    while (a <= b) {
        ll k = ((a + b) / 2);
        cout << k << endl;
        int get;
        cin >> get;

        get *= pattern[ct % n];
        ct++;

        if (get == 0) {
            return 0;
        }
        else if (get == 1) a = k + 1;
        else b = k - 1;
    }
}

/*
3 9
9
1: 3
2: 
*/