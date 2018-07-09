#include <bits/stdc++.h>

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
    
    int a = 0, energy = 0, min_energy = 10e8;
    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        energy += (a - b);
        min_energy = min(energy, min_energy);
        a = b;
    }
    cout << max(0, 0 - min_energy);
}