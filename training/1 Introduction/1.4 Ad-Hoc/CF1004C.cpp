#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <set>
#include <map>

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
    ll n = 0, ans = 0;
    cin >> n;
    vi a(n);
    map<int, int> b;
    map<int, bool> ctd;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
        ctd[a[i]] = false;
    }

    ll unique = b.size();

    for (int i = 0; i < n; i++) {
        if (!ctd[a[i]]) {
            ans += (n - unique - 1);
            if (b[a[i]] > 1) ans++;
            ctd[a[i]] = true;
        }
        b[a[i]]--;
        if (b[a[i]] == 0) unique--;
    }

    cout << ans << "\n";
}