#include <iostream>
#include <vector>
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
    vi permutation;
    permutation.pb(1);
    permutation.pb(2);
    permutation.pb(3);
    permutation.pb(4);

    do {
        cout << "( ";
        for (auto x : permutation) {
            cout << x << " ";
        }
        cout << ")\n";
    } while (next_permutation(permutation.begin(), permutation.end()));
}