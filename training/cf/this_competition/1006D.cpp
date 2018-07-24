#include <vector>
#include <complex>
#include <iostream>
#include <algorithm>

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
    int n = 0;
    cin >> n;
    string trash;
    getline(cin, trash);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    vector<bool> okay(n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        okay[i] = false;
        if (a[i] == b[i]) okay[i] = true;
        else if (a[i] == a[n-i-1] and b[i] == b[n-i-1]) {
            if (i != (n - i - 1)) okay[i] = true;
        }
        else if (a[i] == b[n-i-1] and b[i] == a[n-i-1]) okay[i] = true;
        if (!okay[i]) {
            a[i] = b[i];
            ans++;
        }
    }
    cout << ans << "\n";
}