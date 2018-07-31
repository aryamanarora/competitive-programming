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
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cout << "0";
        else cout << "1";
    }
    cout << "\n";
}