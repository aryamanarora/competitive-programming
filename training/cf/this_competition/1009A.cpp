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
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vi c(n);
    list<int> a(m); // costs andd bills
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < m; i++) cin >> a[i];
    
    int ans = 0;
    for (auto x : c) {
        if (x <= a[0]) {
            ans++;
            a.pop_front;
        }
    }
    cout << ans << "\n";
}