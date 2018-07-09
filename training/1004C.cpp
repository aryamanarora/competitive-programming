#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <set>

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
    ll n = 0;
    cin >> n;
    vi a(n);
    int b[10000];
    for (int i = 0; i < 10000; i++) {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (b[a[i]] < 2) {
            cin >> a[i];
            b[a[i]]++;
        }
    }

    int ans = 0;

    set<int> l;
    for (int i = 0; i < n; i++) {
        if (!binary_search(l.begin(), l.end(), a[i])) {
            set<int> r;
            for (int j = n - 1; j > i; j--) {
                if (!binary_search(r.begin(), r.end(), a[j])) {
                    ans++;
                    r.insert(a[j]);
                }
            }
            l.insert(a[i]);
        }
    }

    cout << ans << "\n";
}