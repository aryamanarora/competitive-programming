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
    ll n = 0;
    cin >> n;
    string a = "ROYGBIV";
    for (int i = 0; i < n / 7; i++) {
        cout << "ROYGBIV";
    }
    n %= 7;

    if (n >= 4) {
        for (int i = 0; i < n; i++) cout << a[i];
    }
    else {
        for (int i = 4 - n; i < 4; i++) cout << a[i];
    }
    cout << "\n";
}