#include <map>
#include <vector>
#include <iostream>
#include <cmath>
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cout << x - (1 - x % 2) << " ";
    }
    cout << "\n";
}