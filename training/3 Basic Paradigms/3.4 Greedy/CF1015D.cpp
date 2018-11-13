#include <vector>
#include <complex>
#include <iostream>

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

    ll n, k, s;
    cin >> n >> k >> s;

    ll max_dist = (n - 1) * k;
    if (max_dist < s or s < k) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    ll pos = 1;
    while (s > n and s > k) {
        pos = ((pos + (n - 1) > n) ? pos - (n - 1): pos + (n - 1));
        cout << pos << " ";
        s -= (n - 1);
        k--;
    }
    while (k > 1) {
        pos = ((pos > 1) ? pos - 1: pos + 1);
        cout << pos << " ";
        s--;
        k--;
    }
    ll move = s;
    pos = ((pos + move > n) ? pos - move: pos + move);
    cout << pos << endl;
    pos != s;
}