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
    ll n = 0;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    int i = 0, j = n - 1;
    ll i_sum = a[i], j_sum = a[j];
    bool i_moved;
    while (i < j) {
        if (i_sum == j_sum) {
            ans = max(ans, i_sum);
            if (i_moved) {
                j--;
                j_sum += a[j];
                i_moved = false;
            }
            else {
                i++;
                i_sum += a[i];
                i_moved = true;
            }
        }
        else if (i_sum < j_sum) {
            i++;
            i_sum += a[i];
            i_moved = true;
        }
        else {
            j--;
            j_sum += a[j];
            i_moved = false;
        }
    }
    cout << ans << "\n";
}